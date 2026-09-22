class Solution {
public:
    int findContentChildren(vector<int>& student, vector<int>& cookie) {
        sort(student.begin(), student.end());
        sort(cookie.begin(), cookie.end());

        int studentPtr = 0;

        for (int cookiePtr = 0;
             studentPtr < student.size() && cookiePtr < cookie.size();
             ++cookiePtr) {

            if (cookie[cookiePtr] >= student[studentPtr]) {
                ++studentPtr;
            }
        }

        return studentPtr;
    }
};