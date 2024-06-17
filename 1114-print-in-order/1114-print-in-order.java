import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class Foo {
    private Lock lock = new ReentrantLock();
    private Condition firstExecuted = lock.newCondition();
    private Condition secondExecuted = lock.newCondition();
    private volatile int count = 1;

    public Foo() {
    }

    public void first(Runnable printFirst) throws InterruptedException {
        lock.lock();
        try {
            printFirst.run();
            count = 2;
            secondExecuted.signal();
        } finally {
            lock.unlock();
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        lock.lock();
        try {
            while (count != 2) {
                secondExecuted.await();
            }
            printSecond.run();
            count = 3;
            firstExecuted.signal();
        } finally {
            lock.unlock();
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        lock.lock();
        try {
            while (count != 3) {
                firstExecuted.await();
            }
            printThird.run();
            count = 1;
            // No need to signal, as first() is the next in sequence
        } finally {
            lock.unlock();
        }
    }
}
