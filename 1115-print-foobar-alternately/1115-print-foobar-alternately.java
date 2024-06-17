import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class FooBar {
    private int n;
    private volatile boolean isFooTurn = true;
    private Lock lock = new ReentrantLock();
    private Condition condition = lock.newCondition();

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        lock.lock();
        try {
            for (int i = 0; i < n; i++) {
                while (!isFooTurn) {
                    condition.await();
                }
                // printFoo.run() outputs "foo". Do not change or remove this line.
                printFoo.run();
                isFooTurn = false;
                condition.signal();
            }
        } finally {
            lock.unlock();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        lock.lock();
        try {
            for (int i = 0; i < n; i++) {
                while (isFooTurn) {
                    condition.await();
                }
                // printBar.run() outputs "bar". Do not change or remove this line.
                printBar.run();
                isFooTurn = true;
                condition.signal();
            }
        } finally {
            lock.unlock();
        }
    }
}
