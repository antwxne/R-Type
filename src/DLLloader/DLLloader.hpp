/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** DLLloader
*/

#ifndef DLLLOADER_HPP_
#define DLLLOADER_HPP_

#include <iostream>
#include <dlfcn.h>
#include <memory>

template<typename T>
class DLLloader {
    public:
        DLLloader(const std::string &filename, std::string &symbol);
        ~DLLloader();
        std::shared_ptr<T> &getInstance();
        int Cdlclose();
    protected:
        void Cdlopen(const std::string &filename, int flag);
        std::string Cdlerror();
        void *Cdlsym(std::string symbol);
        void computeInstance(const std::string &symbol);
    private:
        void *_handle;
        std::shared_ptr<T> _instance;
};

template<typename T>
DLLloader<T>::DLLloader(const std::string &filename, std::string &symbol)
{
    Cdlopen(filename, RTLD_LAZY);
    computeInstance(symbol);
}

template<typename T>
DLLloader<T>::~DLLloader()
{
    std::cout << "DlClose" << std::endl;
    _instance.reset();
    // if (_handle != NULL) {
    //     std::cout << "On Cdlclose !" << std::endl;
    //     Cdlclose();
    // }
}

template<typename T>
void DLLloader<T>::computeInstance(const std::string &symbol)
{
    std::shared_ptr<T> (*entrypoint)(void);
    std::string error;

    if (!_handle)
    {
        _instance = NULL;
        return;
    }
    *(void**)(&entrypoint) = Cdlsym(std::string(symbol));
    error = Cdlerror();
    if (!error.empty())
    {
        _instance = NULL;
        return;
    }
   _instance = (*entrypoint)();
}

template<typename T>
std::shared_ptr<T> &DLLloader<T>::getInstance()
{
    return _instance;
}

template<typename T>
void DLLloader<T>::Cdlopen(const std::string &filename, int flag)
{
    _handle = dlopen(filename.c_str(), flag);
}

template<typename T>
std::string DLLloader<T>::Cdlerror()
{
    char *error = dlerror();
    if (error == NULL)
        return "";
    return std::string(error);
}

template<typename T>
void *DLLloader<T>::Cdlsym(std::string symbol)
{
    return dlsym(_handle, symbol.c_str());
}

template<typename T>
int DLLloader<T>::Cdlclose()
{
    return dlclose(_handle);
}

#endif /* !DLLLOADER_HPP_ */
