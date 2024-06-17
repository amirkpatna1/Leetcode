class FooBar {
    private int n;
    private boolean isFooTurn = true;
    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        synchronized(this) {
            for (int i = 0; i < n; i++) {
            
                while(!isFooTurn) {
                    wait();
                }

                // printFoo.run() outputs "foo". Do not change or remove this line.
                printFoo.run();
                isFooTurn = false;
                notify();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        synchronized(this) {
            for (int i = 0; i < n; i++) {
                while(isFooTurn) {
                    wait();
                }
                // printBar.run() outputs "bar". Do not change or remove this line.
                printBar.run();
                isFooTurn = true;
                notify();
            }
        }
    }
}