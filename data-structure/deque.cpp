template<class T, size_t N>
class deq{
    T* arr = new int[N];
    int l = N / 2, r = N / 2;

    public:
        void clear(){
            fill(arr + l - 1, arr + r + 1, 0);
            l = N / 2, r = N / 2;
        }
        int empty(){
            return r - l == 0;
        }
        int size(){
            return r - l;
        }
        void push_front(T x){
            arr[--l] = x;
        }
        void push_back(T x){
            arr[r++] = x;
        }
        void pop_front(){
            assert(l <= r);
            arr[l++] = 0;
        }
        void pop_back(){
            assert(l <= r);
            arr[--r] = 0;
        }
        int front(){
            assert(l < r);
            return arr[l];
        }
        int back(){
            assert(l < r);
            return arr[r - 1];
        }
};