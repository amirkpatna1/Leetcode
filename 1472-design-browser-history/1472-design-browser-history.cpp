class BrowserHistory {
public:
    deque<string> backward,forwardDeque;
    string currPage;
    BrowserHistory(string homepage) {
        this->currPage = homepage;
    }
    
    void visit(string url) {
        backward.push_back(currPage);
        currPage = url;
        forwardDeque = deque<string>();
    }
    
    string back(int steps) {
        if(!backward.empty())
            forwardDeque.push_front(currPage);
        while(backward.size() > 1 && steps > 1) {
            forwardDeque.push_front(backward.back());
            backward.pop_back();
            steps -= 1;
        }
        if(!backward.empty()){
            currPage = backward.back();
            backward.pop_back();
        }
        return currPage;
    }
    
    string forward(int steps) {
        if(!forwardDeque.empty())
            backward.push_back(currPage);
        while(forwardDeque.size() > 1 && steps > 1) {
            backward.push_back(forwardDeque.front());
            forwardDeque.pop_front();
            steps -= 1;
        }
        if(!forwardDeque.empty()){
            currPage = forwardDeque.front();
            forwardDeque.pop_front();
        }
        return currPage;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */