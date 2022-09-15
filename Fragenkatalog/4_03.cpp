/*
Wurde im Manager/Worker thread model behandelt; thread.pdf ab Folie 59

angegebene Funktion pfn:run:_threaded() ist auf Folie 78 zu finden

Es funktioniert, aber ich würde noch nicht behaupten, dass ich das wirklich
komplett durchblickt udn verstanden habe.
=> ich werde hoffentlich mehr Erklärungen ergänzen

*/

#include<iostream>
#include<thread>
#include<vector>

#include <cstdlib>
#include <cassert>
#include <mutex>

//#### Manager-Klasse aus der Vorlesung #### 

class VirtualQueue {
  private:
    size_t current, last;
    std::mutex queue_mutex;
  public:
    VirtualQueue(size_t number_of_elements)
      : current(0)
      , last(number_of_elements - 1)
    {
      assert(number_of_elements > 0);
    }
    ~VirtualQueue(void) {}
    size_t next_element(void) {
      size_t element;
      queue_mutex.lock(); /* to prevent data race */
      element = current++;
      queue_mutex.unlock();
      return element;
    }
    size_t last_element(void) const {
      /* needed for terminating next_element loop */
      return last;
    }
};

typedef void (*PfNThreadFunc)(size_t thread_id, size_t task_num, void *thread_data); // Folie 76 für Erklärung

static void pfn_thread_apply_thread_func(PfNThreadFunc thread_func,
                                         void *thread_data,
                                         VirtualQueue *vq,
                                         size_t thread_id)
{
  size_t task_num;

  while ((task_num = vq->next_element()) <= vq->last_element())
  {
    thread_func(thread_id, task_num, thread_data);
  }
}

void pfn_run_threaded(size_t num_threads, size_t number_of_tasks, PfNThreadFunc thread_func, void *thread_data) {
  assert(num_threads >= 1 && number_of_tasks > 0);
  if (num_threads > 1) {
    std::vector<std::thread> threads{};
    VirtualQueue vq(number_of_tasks);
    for (size_t thd = 0; thd < num_threads; thd++)
      threads.push_back(std::thread(pfn_thread_apply_thread_func, 
                                    thread_func,thread_data,
                                    &vq, thd));
    for (auto &th : threads) th.join();
  } else
  {
    for (size_t task_num = 0; task_num < number_of_tasks; task_num++)
      thread_func(0,task_num,thread_data);
  }
}



//#############################################################################
//#### ab hier Aufgabe


size_t f(size_t n) { return n<=1 ? 1 : (f(n-1) + f(n-2)); }

void eval_f(size_t thread_id, size_t task_num, void *thread_data){ // k ist gewünschte Anzahl an threads
    size_t *table =(size_t *) thread_data; // void* muss zurück in den richtigen Type gecasted werden
    table[task_num] = f(table[task_num]);
}





//#### main und Hilfsfunktionen####

void show_arr(size_t *arr, size_t len);

int main(void){
  size_t table[] = {39,41,42}; // Laufzeit für 42 ist schon ordentlich lang
  //site_t *table_ptr = &table[0];
  size_t num_tasks = 3; // ist gleichzeitig natürlich Länge des Arrays

  /*
  //gegebene Schleife, für nur einen thread
  for(size_t i = 0; i < num_tasks; i++){
     table[i] = f(table[i]);
  }
  */
  

  printf("mit threads: (sollte schneller gehen)\n");
  size_t num_of_threads = 4;
  
  pfn_run_threaded(num_of_threads, num_tasks, eval_f, table);
  show_arr(table, num_tasks);
  

}

void show_arr(size_t *arr, size_t len){
  printf("[ ");
  for(size_t i = 0; i < len; ++i){
    printf("%ld ", arr[i]);
  }
  printf("]\n");
}
