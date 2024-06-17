class ZeroEvenOdd {
    private int n;
    
    private Lock lock = new ReentrantLock();
    private Condition firstCondition = lock.newCondition();
    private Condition secondCondition = lock.newCondition();
    // private Condition thirdCondition = lock.newCondition();
    private boolean isZerothTurn = true;
    private boolean isOddTurn = false;
    
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        lock.lock();
        try{
            for(int i = 0; i < n; i += 1) {
                while(!isZerothTurn) {
                    firstCondition.await();
                }
                printNumber.accept(0);
                isZerothTurn = false;
                isOddTurn = !isOddTurn;
                secondCondition.signal();
            }
            
        } finally {
            lock.unlock();
        }
        
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        lock.lock();
        try{
            for(int i = 2; i <= n; i += 2) {
            
                while(isOddTurn || isZerothTurn) {
                    secondCondition.await();
                }

                printNumber.accept(i);
                isZerothTurn = true;
                firstCondition.signal();
            }
            
        } finally {
            lock.unlock();
        }
        
        
        
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        lock.lock();
        try{
            for(int i = 1; i <= n; i += 2) {
                while(!isOddTurn || isZerothTurn) {
                    secondCondition.await();
                }
                printNumber.accept(i);
                isZerothTurn = true;
                firstCondition.signal();
            }
        } finally {
            lock.unlock();
        }
        
    }
}