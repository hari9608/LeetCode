/*
929. Unique Email Addresses
Easy
2.4K
283
company
Twitch
company
Google
company
Amazon

Every valid email consists of a local name and a domain name, separated by the '@' sign. Besides lowercase letters, the email may contain one or more '.' or '+'.

    For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" is the domain name.

If you add periods '.' between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name. Note that this rule does not apply to domain names.

    For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.

If you add a plus '+' in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered. Note that this rule does not apply to domain names.

    For example, "m.y+name@email.com" will be forwarded to "my@email.com".

It is possible to use both of these rules at the same time.

Given an array of strings emails where we send one email to each emails[i], return the number of different addresses that actually receive mails.

 

Example 1:

Input: emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.

Example 2:

Input: emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
Output: 3

 

Constraints:

    1 <= emails.length <= 100
    1 <= emails[i].length <= 100
    emails[i] consist of lowercase English letters, '+', '.' and '@'.
    Each emails[i] contains exactly one '@' character.
    All local and domain names are non-empty.
    Local names do not start with a '+' character.
    Domain names end with the ".com" suffix.

Accepted
426.9K
Submissions
636.8K
Acceptance Rate
67.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (4)
Related Topics
Array
Hash Table
String
*/
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> unique_emails;

        for(auto email : emails)
        {
            string vaild_email = "";
            int ele = 0;

            for(ele=0; email[ele]!='@'; ele++)
                if(email[ele] == '+' || email[ele] == '@')    break;
                else if(email[ele] == '.')             continue;
                else vaild_email += email[ele];
            
            while(email[ele] != '@')    ele++;

            for(int ind = ele; ind<email.size(); ind++) vaild_email += email[ind];
            
            unique_emails.insert(vaild_email);      //cout << vaild_email << endl;
        }

        return unique_emails.size();
    }
};