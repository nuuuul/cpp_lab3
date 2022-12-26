/*Вариант 29
Типы аргументов: float,int
1. Сортировка элементов одномерного массива по невозрастанию.
2. АТД Дек.
*/


#include <iostream>
#include <stdio.h>

using namespace std;

template <typename T>
class dynamic_array
{
private:
    int m_size;                                             //кол-во элементов массива
    int m_capacity;                                         //размер выделенной памяти 
    T* m_data;                                              //указатель на область памяти элементов массива

public:
    dynamic_array() : m_size(0), m_capacity(0), m_data(nullptr) //конструктор по умолчанию
    {
        cout << "Вызван конструктор по умолчанию" << endl;
    }

    dynamic_array(const dynamic_array<T>& a)                //конструктор копирования
    {
        cout << "Вызван конструктор копирования" << endl;
        this->m_size = a.m_size;
        m_capacity = m_size;
        m_data = nullptr;
        if (m_size != 0)
            m_data = new T[m_size];
        else
            m_data = 0;
        for (int i = 0; i < m_size; ++i)
            m_data[i] = a.m_data[i];
    }

    dynamic_array(int size)                                 //конструктор, задающий размер массива
    {
        cout << "Вызван конструктор, задающий размер массива" << endl;
        m_size = size;
        m_capacity = size;
        if (size != 0)
            m_data = new T[size];
        else
            m_data = 0;
    }

    ~dynamic_array()                                        //деструктор
    {
        cout << "Вызван деструктор" << endl;
        if (m_data)
            delete[] m_data;
    }

    void resize(int size)                                    //смена размера
    {
        if (size > m_capacity)
        {
            int new_capacity = max(size, m_size * 2);
            T* new_data = new T[new_capacity];
            for (int i = 0; i < m_size; ++i)
                new_data[i] = m_data[i];
            delete[] m_data;
            m_data = new_data;
            m_capacity = new_capacity;
        }
        m_size = size;
    }

    void push_back(T value)                                  //добавление элемента в конец
    {
        resize(m_size + 1);
        m_data[m_size - 1] = value;
    }

    int size() const                                        //метод возвращения размера    
    {
        return m_size;
    }

    T& operator[] (int i)                                   //перегрузка индексации
    {
        return m_data[i];
    }

    void sort_array()
    {
        for (int i = 0; i < m_size; i++)
        {
            for (int j = 0; j < m_size; j++)
            {
                if (m_data[j] <= m_data[j + 1])
                {
                    T b = m_data[j];
                    m_data[j] = m_data[j+1];
                    m_data[j + 1] = b;
                }
            }
        }
    }
};

template<typename T>
ostream& operator << (ostream& out, dynamic_array<T> a)     //перегрузка вывода
{
    for (int i = 0; i < a.size(); ++i)
        out << a[i] << " ";
    return out;
}



int Menu(int choice)
{
    system("cls");
    cout << "Выберите действие" << endl;
    cout << "1.Заполнить массив" << endl;
    cout << "2.Вывести массив" << endl;
    cout << "3.Вывести размер массива" << endl;
    cout << "4.Добавить элемент в массив" << endl;
    cout << "5.Очистить массив" << endl;
    cout << "6.Удалить последний элеент в массиве" << endl;
    cout << "7.Отсортировать массив на невозрастание" << endl;
    cout << "0.Вернуться в главное меню" << endl;
    cin >> choice;
    return choice;
}


int main()
{
    setlocale(LC_ALL, "rus");


    dynamic_array<float> float_array;
    dynamic_array<int> int_array;

    int choosed, deep_choosed, array_size;
    choosed = deep_choosed = -1;
    while (choosed != 0)
    {
        cout << "Какой массив протестим?" << endl;
        cout << "1.Массив float" << endl;
        cout << "2.Массив int" << endl;
        cout << "0.Выйти" << endl;
        cin >> choosed;

        switch (choosed)
        {
        case 1:
            cout << "Вы выбрали массив float" << endl;

            while (deep_choosed != 0)
            {
                deep_choosed = Menu(deep_choosed);

                switch (deep_choosed)
                {
                case 1:                                                 //заполнение массива float
                    cout << "Задайте размер" << endl;
                    cin >> array_size;
                    float float_input;

                    for (int i = 0; i < array_size; i++)
                    {
                        cout << i + 1 << ".";
                        cin >> float_input;
                        float_array.push_back(float_input);
                        cout << float_array[i] << endl;
                    }
                    break;

                case 2:                                               //вывод массива | float
                    if (float_array.size() == 0)
                    {
                        cout << "ERROR : size == 0" << endl;
                        break;
                    }
                    for (int i = 0; i < float_array.size(); i++)
                    {
                        cout << float_array[i] << endl;
                    }
                    break;

                case 3:                                             //вывод размера | float
                    cout << float_array.size() << endl;
                    break;

                case 4:                                             //добавление в конец | float
                    cout << "Введите знаечение" << endl;
                    cin >> float_input;
                    float_array.push_back(float_input);
                    break;

                case 5:                                             //очищение массива | float
                    float_array.resize(0);
                    break;

                case 6:
                    float_array.resize(float_array.size() - 1);     //удаление последнего улемента | float
                    break;

                case 7:                                             //сортировка на невозрастание | float
                    float_array.sort_array();

                case 0:
                    cout << "Возвращаемся..." << endl;
                    break;

                default:
                    cout << "ERROR : unknown number for SWITCH" << endl;
                    break;
                }
                system("PAUSE");
            }
            deep_choosed = -1;
            system("cls");
            break;



        case 2:
            cout << "Вы выбрали массив int" << endl;

            while (deep_choosed != 0)
            {
                deep_choosed = Menu(deep_choosed);

                switch (deep_choosed)
                {
                case 1:                                                 //заполнение массива | int
                    cout << "Задайте размер" << endl;
                    cin >> array_size;
                    int int_input;

                    for (int i = 0; i < array_size; i++)
                    {
                        cout << i + 1 << ".";
                        cin >> int_input;
                        int_array.push_back(int_input);
                        cout << int_array[i] << endl;
                    }
                    break;

                case 2:                                               //вывод массива | int
                    if (int_array.size() == 0)
                    {
                        cout << "ERROR : size == 0" << endl;
                        break;
                    }
                    for (int i = 0; i < int_array.size(); i++)
                    {
                        cout << int_array[i] << endl;
                    }
                    break;

                case 3:                                             //вывод размера | int
                    cout << int_array.size() << endl;
                    break;

                case 4:                                            //добавление в конец | int
                    cout << "Введите значение" << endl;
                    cin >> int_input;
                    int_array.push_back(int_input);
                    break;

                case 5:                                             //чистка массива | int
                    int_array.resize(0);
                    break;

                case 6:
                    int_array.resize(int_array.size() - 1);         //удаление последнего элемента | int
                    break;

                case 7:                                             //сортировка по невозрастанию | int
                    int_array.sort_array();
                    break;

                case 0:
                    cout << "Возвращаемся..." << endl;
                    break;
                default:
                    cout << "ERROR : unknown number for SWITCH" << endl;
                    break;
                }
                system("PAUSE");
            }
            deep_choosed = -1;
            system("cls");

            break;
        default:
            break;
        }
    }
}