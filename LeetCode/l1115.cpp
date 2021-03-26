class FooBar {
private:
    int n;
    pthread_mutex_t one = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t two = PTHREAD_MUTEX_INITIALIZER;

public:
    FooBar(int n) {
        this->n = n;
        pthread_mutex_lock(&two);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            pthread_mutex_lock(&one);
        	printFoo();
            pthread_mutex_unlock(&two);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&two);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            pthread_mutex_unlock(&one);
        }
    }
};