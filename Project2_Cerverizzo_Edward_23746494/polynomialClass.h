
class Poly{
  public:
  Term *head;

  Poly(){
    head = new Term;
  }

  void createAndInsert(int co, int ex){
    Term *temp = new Term;
    temp->c = co;
    temp->e = ex;

    if(head == NULL){
      head = temp;
      return;
    }

  //Traverse and insert
    if(head->next == NULL){//only one node in the list 
      if(head->e > temp->e){
        head->next = temp;
        return;
      }
      else if(head->e < temp->e){
        //create node Before
        temp->next = head;
        head = temp;
        return;
      }
      else{//combine terms
        head->c +=co;
        return;
      }
    }

    else if(head->next != NULL){ //Only works for terms >=2
      Term *curr = head;
      Term *afterCurr = curr->next;
      //Only execute this once.
      if(temp->e > curr->e){//this should only execute when it considers the leading term
          temp->next = head;
          head = temp;
          return;
        }
        //std::cout<< *temp << " is not greater than " << *curr << " (head)" <<std::endl;
      while(curr->next != NULL){//Traverse list to find the right spot
        //current power term exsists, combine coff
        if(curr->e == temp->e){
          //do not create new node
          curr->c += co;
          return;
        }
        //std::cout<< *temp << " is not == to " << *curr <<std::endl;
        //insert between two nodes
        if(curr->e > temp->e && temp->e > afterCurr->e){
          temp->next = curr->next; //new node points to the node after head
          curr->next = temp;       //head points to new node
          return;
        }
        //std::cout<< *temp << " is not <  " << *curr << " and > " << *afterCurr << std::endl;

      curr = curr->next;
      afterCurr = curr->next; //using updated val of curr (this is right)
      }
      //end of the list
      if(curr->e == temp->e){
        curr->c += temp->c;
        return;
      }
      //std::cout<< *temp << " is not == " << *curr << " (tail)" <<std::endl;

      if(curr->next == NULL){
        curr->next = temp;
        return;
      }
      //std::cout<<"temp is" << *temp << "curr is null:" << *curr << "(tail)"<<std::endl;
    }
  }
  

  void print(){
    //std::cout<< "beginning print"<<std::endl;
    Term *curr = new Term;
    curr = head;
    //Term *curr = head; //I think I can get away with just this
    while(curr != NULL){  //if this does not work, try, curr->next != NULL
      std::cout<< *curr <<std::endl;
      curr = curr->next;
    }
  }

  friend std::ostream& operator<< (std::ostream& os, Term t);
  friend Poly operator+(Poly a);
  friend Poly operator-(Poly a);
  friend Poly operator*(Poly a);

};

Poly operator+(Poly a,Poly b){
  std::cout<<"executing operator+"<<std::endl;

  Poly d;

  Term *curr;
  curr = a.head;

  while(curr != NULL){
    d.createAndInsert(curr->c,curr->e);
    curr=curr->next;
  }
  curr = b.head;
  while(curr != NULL){
    d.createAndInsert(curr->c,curr->e);
    curr=curr->next;    
  }
  return d;

}

Poly operator-(Poly a, Poly b){
  Poly d;

  Term *curr;
  curr = a.head;
  while(curr != NULL){
    d.createAndInsert(curr->c,curr->e);
    curr=curr->next;
  }
  curr = b.head;
  while(curr != NULL){
    d.createAndInsert(-1 * curr->c,curr->e);
    curr=curr->next;    
  }
  return d;
}

Poly operator*(Poly a, Poly b){
  Poly d;
  int newCoff;
  int newExp;
  Term *curr1 = a.head;
  Term *curr2 = b.head;

  while(curr1 != NULL){
    while(curr2 != NULL){
      newCoff = curr1->c * curr2->c;
      newExp = curr1->e + curr2->e;
      d.createAndInsert(newCoff,newExp);
      curr2 = curr2->next;
    }
    //reset curr2
    curr2 = b.head;
    curr1 = curr1->next;
  }
  return d;
}


//TODO: FIX
  std::ostream& operator<<(std::ostream& os, Poly p){
    Term *curr = p.head;
    while(curr != NULL){
      if(curr->c >= 0 )
        os << " + " <<  *curr << " ";
      else
        os <<  *curr << " ";
      curr = curr->next;
    }
    return os;
  };

