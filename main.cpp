#include "myQueue.h"
#include <iostream>
#include <string>

using namespace myqueue;

int main() {

    myQueue<string> q;
    insert<string>(q, 3, "three");
    insert<string>(q, 1, "one");
    insert<string>(q, 4, "four");
    insert<string>(q, 2, "two");
    insert<string>(q, 5, "five");
    insert<string>(q, 0, "zero");

    int i = 1;
    while(!empty<string>(q)){
        if(minView(q) == "zero") insert<string>(q, i+1, "zero");
        i++;
        cout << min(q) << endl;
    }

    return 0;
}