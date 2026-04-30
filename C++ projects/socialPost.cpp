#include <bits/stdc++.h>
using namespace std;
struct post_t
{
    int authorID;
    int targetID;
    string message;
};

const int PUBLIC_ID = 0;
void displayPublicPostsCount(const vector<post_t> &posts)
{
    int counter = 0;
    for (post_t post:posts)
    {
        if (post.targetID == PUBLIC_ID)
        {
            counter++;
        }
    }
    cout << "Number of public posts: " << counter << endl;
}

int countNumberOfPosts(const vector<post_t> &posts, int authorID)
{
    int counter = 0;
    for (post_t post:posts)
    {
        if(post.authorID == authorID)
        {
            counter++;
        }
    }
    return counter;
}

int mostProfilicAuthorID(const vector<post_t> &posts)
{
    int maxPosts = 0;
    int maxPostAuthorID = 0;
    for (post_t post:posts)
    {
        
        if (countNumberOfPosts(posts,post.authorID) > maxPosts)
        {
            maxPostAuthorID = post.authorID;
            maxPosts = countNumberOfPosts(posts,post.authorID);
        }
    }
    return maxPostAuthorID;
}

void displayStruct (post_t struct1)
{
    cout << struct1.authorID << "         " << struct1.targetID << "     " << struct1.message<< endl;

}

int countPublicPostsRecursive(const vector<post_t>& posts, int lastIdx)
{
    if (lastIdx == -1)
    {
        return 0;
    }
    int oneIfPostIsPublic = 0;
    if (posts.at(lastIdx).targetID == PUBLIC_ID)
    {
        oneIfPostIsPublic = 1;
    }
    return countPublicPostsRecursive(posts,lastIdx - 1) + oneIfPostIsPublic;
}

void displayAllPosts (const vector<post_t> &posts)
{
    cout << "AuthorID" <<"    "<<"TargetID"<<"   "<<"Message"<<endl;
    cout << "--------" <<"    "<<"--------"<<"   "<<"-------"<<endl;
    for (post_t post:posts)
    {
        displayStruct(post);
        cout << endl;
    }
}

void makeAllPostsHappy(vector<post_t> &posts)
{
    for (post_t post:posts)
    {
        post.message = post.message + " :) ";
    }
} 

vector<post_t> readPostsFromFile(const string &fileName)
{
 vector<post_t> posts;

 ifstream file(fileName);
 if (file.fail()) {
 cout << "Unable to open data file.\n" ;
 exit(EXIT_FAILURE);
 }
 // Read file data
 while (true) {
 post_t post;
 file >> post.authorID;
 // Check if there is in fact data:
 if (file.fail() && file.eof()) {
 break;
 }
 // Read rest of struct
 file >> post.targetID;
 getline(file, post.message);
 posts.push_back(post);
 // Check for errors
 if (file.fail()) {
 cout << "Unable to read course info from file.\n";
 exit(EXIT_FAILURE);
 }
 }
 file.close();
 return posts;
}

int main()
{
    // Initial code to figure out structs:
    post_t demo = {101, 9999, "Just a test"};
    displayStruct(demo);
    vector<post_t> posts = readPostsFromFile("postfile.txt");
    displayPublicPostsCount(posts);
    cout << endl;
    cout << "number of public post with recursive: " << countPublicPostsRecursive(posts,posts.size() - 1) <<endl;
    cout << endl;
    cout << "Most common Author ID: " << mostProfilicAuthorID(posts);
    cout <<endl;
    makeAllPostsHappy(posts);
    displayAllPosts(posts);
    return 0;
}
/*
5. Understanding
◦ If your function accepts a struct named post, how can you access the authorID field
of the struct?
    -post.authorID to access it
◦ What is the prototype for a function named send which accepts a post struct by
reference?
    - void send(post_t &post)

7. Understanding
◦ How can we iterate through a vector of structs named posts using a for-each loop.
    - for(post_t post:posts)
◦ How can we iterate through a vector of structs named posts using a for loop.
    - for (int i = 0; i <posts.size(); i++)

4. Understanding
◦ In this recursion, how is a “bigger” instance of the problem made into a smaller
instance? i.e., how does the recursive step get us to an easier sub problem?
- a function calls itself recursively to solve sub-identical problem

*/