import functools
def log(text):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args,**kw):
            print('%s %s'%(text,func.__name__))
            return func(*args,**kw)
        return wrapper
    return decorator

@log("executed")
def now():
    print('2020-1-17')

now()

'''
import functools

def log(func):
    @functools.wraps(func)
    def wrapper(*args, **kw):
        print('call %s():' % func.__name__)
        return func(*args, **kw)
    return wrapper
'''