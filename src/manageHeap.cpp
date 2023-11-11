# include "rdb_main.hpp"

HeapMgr Mgr;

HeapMgr::HeapMgr() {
    clear();
}

void* HeapMgr::insertAddress(void* address) {
    if (!address)
        return NULL;
    push_back(address);
    return address;
}

void HeapMgr::_clearHeap() {
    MgrIt it = begin();
    while (it != end()) {
        delete * it;
        *it = NULL;
        it = erase(it);
    }
}