def log(text):
    def decorator(func):
        def wraper(*args,**kw):
            print("%s %s():"%(text,func.__name__))
            return func(*args,**kw)
        return wraper
    return decorator

@log("execute")
def now():
    print('2020-1-17')

now()
print(now.__name__)
#error with line 14