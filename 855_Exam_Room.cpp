// 855. Exam Room
// Difficulty: Medium
// URL: https://leetcode.com/problems/exam-room/
//
// There is an exam room with n seats in a single row labeled from 0 to n - 1.
//
// When a student enters the room, they must sit in the seat that maximizes the distance to the closest person. If there are multiple such seats, they sit in the seat with the lowest number. If no one is in the room, then the student sits at seat number 0.
//
// Design a class that simulates the mentioned exam room.
//
// Implement the ExamRoom class:
//
// 	  * ExamRoom(int n) Initializes the object of the exam room with the number of the seats n.
//
// 	  * int seat() Returns the label of the seat at which the next student will set.
//
// 	  * void leave(int p) Indicates that the student sitting at seat p will leave the room. It is guaranteed that there will be a student sitting at seat p.
//
//
//
// Example 1:
//
// Input
// ["ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat"]
// [[10], [], [], [], [], [4], []]
// Output
// [null, 0, 9, 4, 2, null, 5]
//
// Explanation
// ExamRoom examRoom = new ExamRoom(10);
// examRoom.seat(); // return 0, no one is in the room, then the student sits at seat number 0.
// examRoom.seat(); // return 9, the student sits at the last seat number 9.
// examRoom.seat(); // return 4, the student sits at the last seat number 4.
// examRoom.seat(); // return 2, the student sits at the last seat number 2.
// examRoom.leave(4);
// examRoom.seat(); // return 5, the student sits at the last seat number 5.
//
//
//
// Constraints:
//
// 	  * 1 <= n <= 109
//
// 	  * It is guaranteed that there is a student sitting at seat p.
//
// 	  * At most 104 calls will be made to seat and leave.

class ExamRoom {
public:
    set<int> set;
    int n;
    ExamRoom(int n) {
        this->n = n;
    }
    
    int seat() {
        int idx = 0;
        
        if(!set.empty()){
            int dist=*(set.begin());

            int prev = -1;

            for(int s: set){
                if(prev != -1){
                    int d = (s - prev)/2;
                    if(d > dist){
                        dist = d;
                        idx = prev+d;
                    }
                }
                prev = s;
            }

            if(n-1-*(--set.end()) > dist){
                idx = n-1;
            }
        }

        set.insert(idx);
        return idx;
    }
    
    void leave(int p) {
        set.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */