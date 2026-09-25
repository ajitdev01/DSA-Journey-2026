class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique;

        for (string email : emails) {
            string local = "";
            string domain = "";

            int at = email.find('@');

            // Process local name
            for (int i = 0; i < at; i++) {
                if (email[i] == '+') {
                    break;
                }

                if (email[i] != '.') {
                    local += email[i];
                }
            }

            // Domain remains unchanged
            domain = email.substr(at + 1);

            unique.insert(local + "@" + domain);
        }

        return unique.size();
    }
};