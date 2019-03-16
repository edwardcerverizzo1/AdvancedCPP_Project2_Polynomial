class Term{

  public:
  int c, e;
  Term *next;
  Term(){
    c = 0;
    e = 0;
    next = NULL;
  }

  Term(int coff, int exp){
    c = coff;
    e = exp;
    next = NULL;
  }


// Not used
  Term operator+ (Term t){
    if(this->e != t.e){
      std::cout<<"cannot add two different exponet terms together."<<std::endl;
      return Term();
    }
    return Term(this->c +t.c, this->e);
  }

  friend std::ostream& operator<< (std::ostream& os, Term t);
};

  std::ostream& operator<<(std::ostream& os, Term t){
    os << t.c << "x^" << t.e;
    return os;
  };