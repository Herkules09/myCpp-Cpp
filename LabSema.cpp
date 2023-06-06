/*#include <iostream>
#include <vector>
#include <thread>
#include <semaphore>
#include <barrier>
using namespace std;

int counter = 13;

counting_semaphore<10> A{ 3 };
counting_semaphore<10> B{ 0 };
counting_semaphore<10> C{ 1 };

void printA()
{
    for (counter; counter >= 0; --counter)
    {
        A.acquire();
        A.acquire();
        A.acquire();
        cout << "A";
        B.release(2);
    }
}
void printB()
{
    for (counter; counter >= 0; --counter)
    {
        B.acquire();
        cout << "B";
        C.release();
        A.release();
    }
    

}
void printC()
{
    for (counter; counter >= 0; --counter)
    {
        C.acquire();
        C.acquire();
        C.acquire();
        cout << "C";
        B.release();
    }
}


int main()
{
    thread t1(printA);
    thread t2(printB);
    thread t3(printC);

    t1.join();
    t2.join();
    t3.join();

}*/
/*
#include <iostream>
#include <vector>
#include <thread>
#include <semaphore>
#include <barrier>
using namespace std;

int result = 0;
counting_semaphore<10>A{0};
counting_semaphore<10>B{1};
counting_semaphore<10>C{0};

binary_semaphore give_result{ 0 };


//Wywo³uj metody acquire i release na odpowiednich semaforach pomiêdzy fragmentami poni¿szych funkcji
//Po wykonaniu ostatniej dobranej modyfikacji zmiennej result wywo³aj give_result.release(), aby umo¿liwiæ poprawne zakoñczenie dzia³ania programu
void math1()
{
    A.acquire();
    give_result.release();
    result += 12;
    result *= 3;
    result -= 45;
}
void math2()
{
    B.acquire();
    result = result ^ 2;
    result = 3;
    result = result / 2;
    C.release(2);
}
void math3()
{
    C.acquire();
    ++result;
    if (result > 30)
    {
        result = 30;
    }
    result += 6;
    A.release();
}
void finish1()
{
    give_result.acquire();
    cout << result << endl;
  
    //odblokuj wszystkie semafory aby zapewniæ poprawne zakoñczenie programu
}


int main()
{
    thread t1(math1);
    thread t2(math2);
    thread t3(math3);

    thread finish(finish1);

    t1.join();
    t2.join();
    t3.join();
    finish.join();
}*/





