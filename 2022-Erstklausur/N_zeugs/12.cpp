#include<iostream>
#include<vector>
#include<thread>
#include<mutex> // muss man dann benutzen


void count_characters(size_t *counters,const char *sptr, size_t len){
    std::mutex my_mutex; //neu
  for (size_t idx = 0; idx < len; idx++)
    my_mutex.lock();
    counters[static_cast<size_t>(sptr[idx])]++; // es könnte ja sonst passieren, dass zwei threads gleichzeitig für das gleiche Zeichen zählen und in tabelle schreiben wollen. Dann wird falsch gezählt, weil der Wert dann ja nur 1x erhöht wird
    my_mutex.unlock();
  }


void count_characters_threaded(const char *str, size_t strlength, size_t num_threads) {
  size_t counters[256] = {0};
  std::vector<std::thread> threads{};
  const size_t width = strlength/num_threads;
  for (size_t t = 0; t < num_threads; t++)
    threads.push_back(std::thread(count_characters,counters, str + t * width, t < num_threads - 1 ? width : (strlength - t * width))); // count_characters wird jeweils mit einem Teilstring aufgerufen
  for (auto &&th : threads) th.join();
  for (size_t idx = 0; idx < 256; idx++)
    if (counters[idx] > 0)
      std::cout << idx << "\t" << counters[idx] << std::endl;
}

/*
Also muss man das Zählen selber muten, damit nicht gleichzeitig ein Zeichen gezählt wird und dadurch der Zähler nur 1x inkrementiert wird.

Es macht keinen Sinn hier zu threaden, da der thread bei jedem Iterationsschritt auf einen anderen thread warten muss.

*/
