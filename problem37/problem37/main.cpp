#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	char* Serialize(TreeNode *root)
	{
		string s;
		Serialize(root, s);
		char* result = new char[s.size() + 1];
		strcpy(result, s.c_str());
		return result;
	}

	TreeNode* Deserialize(char *str) {
		if (str == nullptr)
			return nullptr;
		string s(str);
		return Deserialize(s);
	}

	TreeNode* DeserializeSS(char *str)
	{
		stringstream ss(str);
		return DeserializeSS(ss);
	}

private:
	void Serialize(TreeNode* root, string& s)
	{
		if (root == nullptr) {
			s += "#,";
			return;
		}

		s += to_string(root->val);
		s.push_back(',');

		Serialize(root->left, s);
		Serialize(root->right, s);

	}
	TreeNode* Deserialize(string& s)
	{
		if (s[0] == '#')
		{
			s = s.substr(2);
			return nullptr;
		}
		TreeNode* result = new TreeNode(stoi(s));
		s = s.substr(s.find_first_of(',') + 1);
		result->left = Deserialize(s);
		result->right = Deserialize(s);
		return result;
	}

	TreeNode* DeserializeSS(stringstream& ss)
	{
		string str;
		getline(ss, str, ',');
		if (str == "#")
			return nullptr;
		TreeNode* node = new TreeNode(stoi(str));
		node->left = DeserializeSS(ss);
		node->right = DeserializeSS(ss);
		return node;
	}
};