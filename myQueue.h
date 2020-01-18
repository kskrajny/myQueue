#ifndef MYQUEUE_MYQUEUE_H
#define MYQUEUE_MYQUEUE_H

#include <unordered_map>
#include <iostream>
#include <set>

using namespace std;

namespace myqueue {

    template <class T>
    class Pair {
    public:
        int priority;
        T obj;

        friend bool operator < (const Pair<T>& l, const Pair<T>& r){
            if (l.priority != r.priority) {
                return (l.priority < r.priority);
            } else {
                return (l.obj < r.obj);
            }
        }

        Pair<T>(int priority, T obj){
            this->priority = priority;
            this->obj = obj;
        }
    };

    template <class T>
    class myQueue {
    public:
        set<Pair<T>> queue;
        unordered_map<T, int> map;
    };

    template <class T>
    void insert(myQueue<T> &q, int priority, T obj){
        auto it_map = q.map.find(obj);
        if (it_map != q.map.end()) {
            Pair<T> p(it_map->second, obj);
            q.queue.erase(p);
            q.map.erase(it_map);
        }
        auto it = q.queue.insert(Pair<T>(priority, obj));
        q.map.insert({obj, priority});
    }

    template <class T>
    T min(myQueue<T> &q){
        T obj = q.queue.begin()->obj;
        q.map.erase(obj);
        q.queue.erase(q.queue.begin());
        return obj;
    }

    template <class T>
    T minView(myQueue<T> &q){
        T obj = q.queue.begin()->obj;
        return obj;
    }

    template <class T>
    bool empty(myQueue<T> &q){
        return q.queue.empty();
    }
};
#endif //MYQUEUE_MYQUEUE_H
