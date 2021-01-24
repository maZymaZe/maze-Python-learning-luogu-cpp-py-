from multiprocessing import Pool
import os,time,random

def long_time_process(name):
    print('run task %s (%s)'%(name,os.getpid()))
    start=time.time()
    time.sleep(random.random()*3)
    end=time.time()
    print('task %s runs %0.2f seconds'%(name,end-start))

if __name__=='__main__':
    print("parent process %s."%os.getpid())
    p=Pool(4)
    for i in range(5):
        p.apply_async(long_time_process,args=(i,))
    print('waiting for all subprocesses done...')
    p.close()
    p.join()
    print("all processes done")
