

/*
  file: main.cc
  This program uses a priority queue of "bottles"
  and simulates their arrival and removal from the queue.
  arrival - bottle of stated capacity is added to the queue,
            "sifting up" to its prioritized spot.
  service - that much beverage is removed from one or more
            bottles at the head of the queue.
            If the last bottle used to service the request is
            not fully drained it is put back into the queue,
            "sifting down" to its prioritized spot.
  notes: the terms sifting up/down refer to the classical implementation
         of a priority queue as a tree-based heap; this may not
         be the case in this actual implementation.
  Input: data formatted as
      event-1 int-1
      event-2 int-2
         :    :
      event-n int-n
  where event-i is arrive/serve
  and int-i is a positive integer

  Output: events as they happen w/ commentary on how they
          are handled and current state of the queue
*/
#include <iostream>
#include <string>
#include <queue>
#include <cassert>
#include <fstream>
//new
#include <sstream>
#include <malloc.h>
#include <string.h>
using namespace std;

class Seafood {

   friend ostream& operator<<(ostream& o, const Seafood& b)
      { return o << "seafood[" << b.cap << "]"; }
   friend bool operator<(const int i, const Seafood& b)
      { return i < b.cap; }
   friend bool operator==(const int i, const Seafood& b)
      { return i == b.cap; }
   friend int operator+(const int i, const Seafood& b)
      { return i + b.cap; }
   public:
      bool operator<(const Seafood& b) const { return cap < b.cap; }
      Seafood(int i, string expiration) : cap(i), expiration(expiration) {}
      string getExp()
      {
          return expiration;
      }


   private:
      int cap;
      string expiration;
};

/****************************************************************
*     date comparison
*****************************************************************/
string convert(const string date) {
   // regex exp("(..)/(..)/(....)");
   const char *d = date.c_str();
   int len = strlen(d)+1;
   char *month = (char *)malloc(sizeof(char)*len);
   strncpy(month, d, len);
   month[len] = '\0';
   // cout << month << endl;

   char *day = strstr(month, "/");
   if (!day) {
      free(month);
      return date;
   }
   *day = '\0';
   day++;
   char *year = strstr(day, "/");
   if (!year) {
      free(month);
      return date;
   }
   *year = '\0';
   year++;
   stringstream ss;
   ss << year << "/" << month << "/" << day;
   string s = ss.str();
   free(month);
   return s;

}
/****************************************************************
*      END date comparison
****************************************************************/



//*************************************************************//
//function to print elements from queue
void print (priority_queue<Seafood> pq) {
   while (!pq.empty()) {
      Seafood largest = pq.top();
      pq.pop();
      cout << largest << (!pq.empty() ? ", " : "");
   }
   cout << endl;
}

/*bool expComparison(Seafood obj1, Seafood obj2)
{
    String exp1 = obj1.getExp();


   return true;

}*///ends expComparison method

class Compare {
public:
    bool operator()(Seafood& boxA, Seafood& boxB)
    {
        string boxADate = boxA.getExp();
        string boxBDate = boxB.getExp();


        if (convert(boxADate) < convert(boxBDate)) {

            return true;
          } else {

            return false;
          }

    }
};

//creates priority queues
//priority_queue <Seafood, vector<Seafood>,Compare > test;
priority_queue <Seafood> shrimp_queue;
priority_queue <Seafood> lobster_queue;
priority_queue <Seafood> crab_queue;
priority_queue <Seafood> swordfish_queue;


int main (int argc, char *argv[]) {

   //Local variables
   string event;      //event either buy or stock
   string date;       //expiration date
   string seafoodType;//seafoodType = lobster, crabs ....etc
   int amount;        //amount of specific seafood
   //string line;     //reads data from a file
   int boxAmount;     //amount per box


   //asks user for input
   cout <<"Stock or Buy seafood: "<<endl;

   while (cin >> event >> date >> seafoodType >> amount) {

      if(seafoodType == "shrimp")
      {
        cout << "Queue: "; print(shrimp_queue);
        cout << "Event: " << event << " w/ value " << amount << endl;
        cout << "Expiration Date: " << date <<endl;
        cout << "Seafood Type: " << seafoodType<<endl;

      }
      else if(seafoodType == "crab"){
        cout << "Queue: "; print(crab_queue);
        cout << "Event: " << event << " w/ value " << amount << endl;
        cout << "Expiration Date: " << date <<endl;
        cout << "Seafood Type: " << seafoodType<<endl;

      }
      else if(seafoodType == "swordfish"){
        cout << "Queue: "; print(swordfish_queue);
        cout << "Event: " << event << " w/ value " << amount << endl;
        cout << "Expiration Date: " << date <<endl;
        cout << "Seafood Type: " << seafoodType<<endl;

      }
      else if(seafoodType == "lobster"){
        cout << "Queue: "; print(lobster_queue);
        cout << "Event: " << event << " w/ value " << amount << endl;
        cout << "Expiration Date: " << date <<endl;
        cout << "Seafood Type: " << seafoodType<<endl;
      }
      else{
        cout<<"Invalid seafood!"<<endl;
      }


      //tests for user event input
      if (event == "stock"){

         //Also need to test to which queue the items will be added

         //displays adding stocks to pile and adds them to respective queue
         cout << "Adding seafood to stockpile" << endl;
         //seafood.push(Seafood(amount));

         if(seafoodType == "shrimp")
         {
            for(int i = 0; i < amount; i++)
            {
                boxAmount = 50;
                Seafood shrimp(boxAmount, date);
                shrimp_queue.push(shrimp);


            }
            cout << "Shrimp's queue: "; print(shrimp_queue);
            cout<<"You currently have: "<<shrimp_queue.size()<<" Boxes"<<endl;


         }
         else if(seafoodType == "crab")
         {
            for(int i = 0; i < amount; i++)
            {
                boxAmount = 6;
                Seafood crab(boxAmount, date);
                crab_queue.push(crab);

            }
            cout << "Crab's queue: "; print(crab_queue);
            cout<<"You currently have: "<<crab_queue.size()<<" Boxes"<<endl;
         }
         else if(seafoodType == "swordfish")
         {
            for(int i = 0; i < amount; i++)
            {
                boxAmount = 8;
                Seafood swordfish(boxAmount, date);
                swordfish_queue.push(swordfish);

            }
            cout << "Swordfish's queue: "; print(swordfish_queue);
            cout<<"You currently have: "<<swordfish_queue.size()<<" Boxes"<<endl;
         }
         else if(seafoodType == "lobster")
         {
            for(int i = 0; i < amount; i++)
            {
                boxAmount = 4;
                Seafood lobster(boxAmount, date);
                lobster_queue.push(lobster);

            }
            cout << "Lobster's queue: "; print(lobster_queue);
            cout<<"You currently have: "<<lobster_queue.size()<<" Boxes"<<endl;
         }
         else
         {
            cout<<"please enter a valid seafood"<<endl;
         }




      //buying event
      } else if (event == "buy"){

         if(seafoodType == "lobster")
         {


            //Prints a message to the user
            cout << "Using some seafood from stockpile" << endl;

            int vol = 0;

            while ( vol < amount ) {

            //tests if queue is not empty
            if (!lobster_queue.empty()) {

               Seafood top = lobster_queue.top();
               lobster_queue.pop();
               if (vol + top < amount) {
                  vol = vol + top;
               } else if (vol + top == amount) {
                  vol = vol + top;
                  break;
               } else {
                  int remains = (vol + top) - amount;
                  vol = amount;
                  lobster_queue.push(Seafood(remains, date));
                  break;
               }
            } else {

               //prints a message to th user that it doesn't have enough seafood
               assert(lobster_queue.empty());
               cout << "Seafood supply exhausted, " <<
                       "can't meet remaining amount " <<
                       (amount - vol) << endl;
               break;

            }//ends else
            }//ends while
        }else if(seafoodType == "shrimp"){
            //Prints a message to the user
            cout << "Using some seafood from stockpile" << endl;

            int vol = 0;

            while ( vol < amount ) {

            //tests if queue is not empty
            if (!shrimp_queue.empty()) {

               Seafood top = shrimp_queue.top();
               shrimp_queue.pop();
               if (vol + top < amount) {
                  vol = vol + top;
               } else if (vol + top == amount) {
                  vol = vol + top;
                  break;
               } else {
                  int remains = (vol + top) - amount;
                  vol = amount;
                  shrimp_queue.push(Seafood(remains, date));
                  break;
               }
            } else {

               //prints a message to th user that it doesn't have enough seafood
               assert(shrimp_queue.empty());
               cout << "Seafood supply exhausted, " <<
                       "can't meet remaining amount " <<
                       (amount - vol) << endl;
               break;

            }//ends else
            }//ends while

        }else if(seafoodType == "crab")
        {
            //Prints a message to the user
            cout << "Using some seafood from stockpile" << endl;

            int vol = 0;

            while ( vol < amount ) {

            //tests if queue is not empty
            if (!crab_queue.empty()) {

               Seafood top = crab_queue.top();
               crab_queue.pop();
               if (vol + top < amount) {
                  vol = vol + top;
               } else if (vol + top == amount) {
                  vol = vol + top;
                  break;
               } else {
                  int remains = (vol + top) - amount;
                  vol = amount;
                  crab_queue.push(Seafood(remains, date));
                  break;
               }
            } else {

               //prints a message to th user that it doesn't have enough seafood
               assert(crab_queue.empty());
               cout << "Seafood supply exhausted, " <<
                       "can't meet remaining amount " <<
                       (amount - vol) << endl;
               break;

            }//ends else
            }//ends while


        }else if(seafoodType == "swordfish"){

            cout << "Using some seafood from stockpile" << endl;

            int vol = 0;

            while ( vol < amount ) {


            if (!swordfish_queue.empty()) {

               Seafood top = swordfish_queue.top();
               swordfish_queue.pop();
               if (vol + top < amount) {
                  vol = vol + top;
               } else if (vol + top == amount) {
                  vol = vol + top;
                  break;
               } else {
                  int remains = (vol + top) - amount;
                  vol = amount;
                  swordfish_queue.push(Seafood(remains, date));
                  break;
               }
            } else {

               //prints a message to th user that it doesn't have enough seafood
               assert(swordfish_queue.empty());
               cout << "Seafood supply exhausted, " <<
                       "can't meet remaining amount " <<
                       (amount - vol) << endl;
               break;

            }//ends else
            }//ends while

        }


      }/*ends elseif*/ else {

        //prints ignoring event
        cout << "Ignoring event " << event <<  endl;

      }//ends else

   }//ends outer while
    cout << "Queue: "; print(lobster_queue);


   while (!lobster_queue.empty()) {
     Seafood largest = lobster_queue.top();
     lobster_queue.pop();
     cout << largest << endl;
   }

}


/*

   Data file:

arrive 10
arrive  5
arrive  7
serve   9
serve   8
arrive  4
arrive  3
serve  11
arrive  7
serve   9
arrive  2
serve   8
serve  10

*/
