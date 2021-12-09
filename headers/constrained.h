template <typename T, int l, int u>
class constrained{
    private:
    T val;
    T lowerbound;
    T upperbound;
    public:
    constrained(const int v){
        val = v;
        lowerbound = l;
        upperbound = u;
    }

    T operator=(T x){
        if(x < lowerbound){
            this->val = lowerbound;
            return lowerbound;
        }
        if(x > upperbound){
            this->val = upperbound;
            return upperbound;
        }
        this->val = x;
        return x;
    }
    T operator+=(T x){
        if(this.val+x < lowerbound){
            this->x = lowerbound;
            return lowerbound;
        }
        if(this.val+x > upperbound){
            this-> x = lowerbound;
            return upperbound;
        }
        this->val = this->val+x;
        return this->val+x;
    }
    T operator-=(T x){
        if(this->val-x < lowerbound){
            this->val = lowerbound;
            return lowerbound;
        }
        if(this->val-x > upperbound){
            this->val = upperbound;
            return upperbound;
        }
        this->val = this->val-x;
        return this->val-x;
    }
    T operator*=(T x){
        if(this->val*x < lowerbound){
            this->val = upperbound;
            return upperbound;            
        }
        if(this->val*x > upperbound){
            this->val = upperbound;
            return upperbound;            
        }
        this->val = this->val*x;
        return this->val*x;
    }
    T operator/=(T x){
        if(this->val/x < lowerbound){
            this->val = upperbound;
            return upperbound;            
        }
        if(this->val/x > upperbound){
            this->val = upperbound;
            return upperbound;            
        }
        this->val = this->val/x;
        return this->val/x;
    }
    operator int(){
        return val;
    }
    operator float(){
        return val;
    }
    operator double(){
        return val;
    }
};