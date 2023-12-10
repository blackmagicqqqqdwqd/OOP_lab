

#include <iostream>
#include<algorithm >
# include <random>
int main()
{
    int max_value, min_value;
    max_value = 9999;
    min_value = 1;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(min_value, max_value);

    int m, n;
    m = 5;
    n = 5;

    std::cout <<"specify the width"<<"\n";
    std::cin >> n;
    std::cout << "specify the hight" << "\n";
    std::cin >> m;
    std::cout << "" << "\n";
    int a = 0;
    int** arr = new int* [m];


    std::cout << "the original" << "\n"; 
    std::generate(arr, arr + m, [&]() {return  new int[n];});
    for (int i = 0; i < m; i++) std::generate(*(arr + i), (*(arr + i) + n), [&]() {return  dist(rng);});

    for (int i = 0; i < m; i++)
    {
        for (int w = 0; w < n; w++)
        {
            if (  (int)(*(*(arr + i) + w)) > 0 && *(*(arr + i) + w) < 10) std::cout << "000" << * (*(arr + i) + w) << " ";
            if (*(*(arr + i) + w) > 9 && *(*(arr + i) + w) < 100) std::cout << "00" << *(*(arr + i) + w) << " ";
            if (*(*(arr + i) + w) > 99 && *(*(arr + i) + w) < 1000) std::cout << "0" << *(*(arr + i) + w) << " ";
            if ( *(*(arr + i) + w) > 999) std::cout  << *(*(arr + i) + w) << " ";
           // std::cout << *(*(arr + i) + w) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";



    int number_max = min_value - 1, number_min = max_value + 1;
    int m_max, m_min;
    m_max = 1;
    m_min = 0;

    std::cout << "the converted" << "\n";
    for (int i = 0; i < m; i++)
    {
        if (*(std::max_element(*(arr + i), *(arr + i) + n)) > number_max) {
            number_max = *(std::max_element(*(arr + i), *(arr + i) + n));
            m_max = i;
        }
        if (*(std::min_element(*(arr + i), *(arr + i) + n)) < number_min) {
            number_min = *(std::min_element(*(arr + i), *(arr + i) + n));
            m_min = i;
        }
    }


    std::cout << "max:" << number_max << " min:" << number_min << "\n" << "\n";
    std::cout << "line max:" << m_max + 1 << " line min:" << m_min + 1 << "\n" << "\n";




    int* temp = arr[m_max];
    arr[m_max] = arr[m_min];
    arr[m_min] = temp;

    for (int i = 0; i < m; i++)
    {
        for (int w = 0; w < n; w++)
        {
            if ((int)(*(*(arr + i) + w)) > 0 && *(*(arr + i) + w) < 10) std::cout << "000" << *(*(arr + i) + w) << " ";
            if (*(*(arr + i) + w) > 9 && *(*(arr + i) + w) < 100) std::cout << "00" << *(*(arr + i) + w) << " ";
            if (*(*(arr + i) + w) > 99 && *(*(arr + i) + w) < 1000) std::cout << "0" << *(*(arr + i) + w) << " ";
            if (*(*(arr + i) + w) > 999) std::cout << *(*(arr + i) + w) << " ";
           // std::cout << *(*(arr + i) + w) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

}

