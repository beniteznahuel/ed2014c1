struct ArrayListStr{
    int* elems;
    int capacity;
    int last;
}

struct ArrayListIteratorStr{
    ArrayList list;
    int index;
}

ArrayList emptyArrayList(){
    ArrayList newArray = new ArrayListStr;
    newArray -> elems = new int[1];
    newArray -> capacity = 1;
    newArray last = 0;
    return newArray;
}

void deleteArrayList(ArrayList& l){
    delete[] l -> elems;
    delete(l);
}

bool isEmpty(ArrayList l){
    return l -> last == 0;
}

int size(ArrayList l){
    return l -> last;
}

int get(ArrayList l, int i){
    return l -> elem[i];
}

void set(ArrayList& l, int i, int n){
    l -> elem[i] = n;
}

void resize(ArrayList& l){
    if(l -> capacity == l -> last){
        int* aux = new int[l->capacity <<= 1];
        for(int i=0; i<l;i++)
            aux[i] = l->elems[i];
        delete[] l->elems;
        l->elems=aux;
    }
}

void push(ArrayList& l, int n){
    resize(l);
    l -> elem[l -> last] = n;
}

int pop(ArrayList& l){
    int ret = l -> elem[l -> last];
    l -> last = l -> last - 1;
    return ret;
}

ArrayListIterator iterate(ArrayList l){
    ArrayListIterator it = new ArrayListStr;
    it -> list = l;
    it -> index = 0;
    return it;
}

void deleteIterator(ArrayListIterator& it){
    delete(it);
}

bool valid(ArrayListIterator it){
    return (it -> index) < (it -> list -> last);
}

int getCurrent(ArrayListIterator it){
    return it -> list -> elems[it -> index];
}

void setCurrent(ArrayListIterator it, int n){
    set(it -> list, it -> index, n);
}

void next(ArrayListIterator& it){
    it -> index = it -> index + 1;
}

void insert(ArrayListIterator it, int n){
    resize(it -> l);
    for(i=it -> list -> last; i>(it->index);i--)
        set(it -> list, i++, it -> elem[i]);
}



