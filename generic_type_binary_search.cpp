/* 
 *    Program:      Searching a generic type value in a generic type std::vector
 *                  with Binary Search Algorithm using function templates.
 * 
 *    Made by:      Ransomware3301 (https://github.com/ransomware3301)
 *    Date:         02-11-2023
 */

#include <iostream>
#include <vector>

#define DEBUG 1


typedef int TYPE;

typedef struct result {
    int index;
    bool is_found;
} result_t;


template<typename T> void input_vector(std::vector<T> *, int);
template<typename T> void print_vector(std::vector<T> *);
template<typename T> void insertion_sort(std::vector<T> *);
template<typename T> result_t binary_search(std::vector<T> *, T);


int main(int argc, char *argv[])
{
    std::vector<TYPE> v;
    TYPE elem;
    result_t res;
    int size;

    // Request vector size that needs to be > 0 necessarily
    do
    {
        std::cout << "Insert vector size: ";
        std::cin >> size;
    }
    while(size < 1);

    // Aesthetic spacer for terminal output
    std::cout << std::endl;
    
    input_vector(&v, size);
    if(DEBUG)   print_vector(&v);

    if(DEBUG)   std::cout << "\n[Sorting vector...]" << std::endl;

    insertion_sort(&v);
    if(DEBUG)   print_vector(&v);

    // Aesthetic spacer for terminal output
    std::cout << std::endl;

    std::cout << "Insert element to search: ";
    std::cin >> elem;

    // Searches the element in the vector with the Binary Search Algorithm 
    res = binary_search(&v, elem);

    // Aesthetic spacer for terminal output
    std::cout << std::endl;

    if(res.is_found){
        std::cout << "=> Value " << elem << " found at index " << res.index << std::endl;
    }
    else{
        std::cout << "=> Value " << elem << " was not found." << std::endl;
    }

    // Aesthetic spacer for terminal output
    std::cout << std::endl;

    return 0;
}


/* 
 *  Fills the vector with user input
 */
template<typename T>
void input_vector(std::vector<T> *v, int size)
{
    int i;
    T elem;

    for(i = 0; i < size; i++)
    {
        std::cout << "Insert element at index " << i << ": ";
        std::cin >> elem;
        v->push_back(elem);
    }
}


/*
 *  Prints the passed vector to terminal
 */
template<typename T>
void print_vector(std::vector<T> *v)
{
    int i;
    int size;

    size = v->size();

    std::cout << "\nVector Contents:" << std::endl;

    for(i = 0; i < size; i++)
    {
        std::cout << v->at(i) << " ";
    }
    
    std::cout << std::endl;
}


/*
 *  Sorts the passed vector with Insertion Sort Algorithm
 */
template<typename T>
void insertion_sort(std::vector<T> *v)
{
    int i, j;
    int size;
    T temp;


    size = v->size();

    for(i = 0; i < size - 1; i++)
    {
        for(j = i + 1; j < size; j++)
        {
            if(v->at(j) < v->at(i))
            {
                temp = v->at(j);
                v->at(j) = v->at(i);
                v->at(i) = temp;
            }
        }
    }
}


/* 
 *  Performs a binary search on a template vector
 */
template<typename T>
result_t binary_search(std::vector<T> *v, T elem)
{
    result_t res;
    int l, r, center;
    int size;


    size = v->size();

    if(size < 2)
    {
        // Handling case where array dim == 1
        if( v->at(0) == elem )
        {
            res.index = 0;
            res.is_found = true;
        }
        else
        {
            res.index = -1;
            res.is_found = false;
        }
    }
    else
    {
        /* Border flags, one at start and one at end of vector */
        l = 0;
        r = size - 1;

        /* Default vaules in case element isn't found */
        res.index = -1;
        res.is_found = false;

        while( !res.is_found && l < r )
        {
            /* Calculating the center of the current vector partition */
            center = (l + r) / 2;

            if( v->at(center) == elem )
            {
                res.index = center;
                res.is_found = true;
            }
            else if( v->at(l) == elem )
            {
                res.index = l;
                res.is_found = true;
            }
            else if( v->at(r) == elem )
            {
                res.index = r;
                res.is_found = true;
            }
            else if( elem > v->at(center) )
            {
                l = center + 1;
            }
            else
            {
                r = center - 1;
            }
        }
    } 

    return res;
}
