 #include <iostream>
 #include <vector>
 using namespace std;
 class TreeNode {
 public:
    string name; 
    vector<TreeNode*> children; 
    TreeNode(string name) {
        this->name = name;
    }
    void addChild(TreeNode* child) {
        children.push_back(child);
    }
 };
 void printTree(TreeNode* root, int level = 0) {
    if (!root) 
        return;
    for (int i = 0; i < level; i++) cout << "  ";
    cout << "- " << root->name << endl;
    for (TreeNode* child : root->children) {
        printTree(child, level + 1);
    }
 }
 int main() {
    string bookName;
    cout << "Enter book name: ";
    getline(cin, bookName);
    TreeNode* book = new TreeNode(bookName);
    int numChapters;
    cout << "Enter number of chapters: ";
    cin >> numChapters;
    cin.ignore(); // To handle newline
    for (int i = 0; i < numChapters; i++) {
        string chapterName;
        cout << "Enter name of Chapter " << i + 1 << ": ";
        getline(cin, chapterName);
        TreeNode* chapter = new TreeNode(chapterName);
        book->addChild(chapter);
        int numSections;
        cout << "Enter number of sections in " << chapterName << ": ";
        cin >> numSections;
        cin.ignore();
        for (int j = 0; j < numSections; j++) {
            string sectionName;
            cout << "Enter name of Section " << j + 1 << " in " << chapterName << ": ";
            getline(cin, sectionName);
            TreeNode* section = new TreeNode(sectionName);
            chapter->addChild(section);
            int numSubsections;
            cout << "Enter number of subsections in " << sectionName << ": ";
            cin >> numSubsections;
            cin.ignore();
            for (int k = 0; k < numSubsections; k++) {
                string subsectionName;
                cout << "Enter name of Subsection " << k + 1 << " in " << 
sectionName << ": ";
                getline(cin, subsectionName);
                TreeNode* subsection = new TreeNode(subsectionName);
                section->addChild(subsection);
            }
        }
    }
    cout << "\nBook Structure:" << endl;
   printTree(book);
      return 0;
 }