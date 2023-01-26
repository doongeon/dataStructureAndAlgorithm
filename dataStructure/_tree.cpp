// tree

#include <iostream>
#include <queue>

struct node
{
    std::string position;
    node* first;
    node* second;
};

struct org_tree
{
    node* root;

    static org_tree create_org_structure(const std::string& pos)
    {
        org_tree tree;
        tree.root = new node {pos, NULL, NULL};
        return tree;
    }

    static node* find(node* root, const std::string& value) // inorder traversal
    {
        if (root == NULL) // ���� ��尡 NULL�� ���
            return NULL;

        if (root->position == value) // ���� ��尡 ã�� ����� ���
            return root;

        auto firstFound = org_tree::find(root->first, value); // ���� �ڽĳ��� �̵�

        if (firstFound != NULL) // ���� �ڽĳ�尡 �ִ� ��� �� �ּҸ� ����.
            return firstFound;

        return org_tree::find(root->second, value); // ������ �ڽĳ��� �̵�
    }

    static void preOrder(node* start) // ������ȸ 
    {
        if (!start) // ���� �ּҰ� NULL�� ���
            return;

        std::cout << start->position << ", ";

        preOrder(start->first);
        preOrder(start->second);
    }

    static void inOrder(node* start) // ������ȸ
    {
        if(!start)
            return;

        inOrder(start->first);
        std::cout << start->position << ", ";
        inOrder(start->second);
    }

    static void postOrder(node* start)
    {
        if(!start)
            return;
        
        postOrder(start->first);
        postOrder(start->second);
        std::cout << start->position << ", ";
    }

    bool addSubordinate(const std::string& manager, const std::string& subordinate)
    {
        auto managerNode = org_tree::find(root, manager);

        if(!managerNode)
        {
            std::cout << manager << "��(��) ã�� �� �����ϴ�." << std::endl;
            return false;
        }

        if(managerNode->first && managerNode->second)
        {
            std::cout << manager << " �Ʒ��� " << subordinate << "��(��) �߰��� �� �����ϴ�." << std::endl;
            return false;
        }

        if(!managerNode->first)
        {
            managerNode->first = new node {subordinate, NULL, NULL};
        }
        else
        {
            managerNode->second = new node {subordinate, NULL, NULL};
        }

        std::cout << manager << " �Ʒ��� " << subordinate << "��(��) �߰��߽��ϴ�." << std::endl;

        return true;
    }

    static void levelOrder(node* start)
    {
        if(!start)
            return;
        
        std::queue<node*> q;
        q.push(start);

        while(!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto current = q.front();
                q.pop();

                std::cout << current->position << ", ";
                if (current->first)
                    q.push(current->first);
                if(current->second)
                    q.push(current->second);
            }

            std::cout << std::endl;
        }
    }
};

int main()
{
    auto tree = org_tree::create_org_structure("CEO");

    tree.addSubordinate("CEO", "�λ���");
    tree.addSubordinate("�λ���", "IT����");
    tree.addSubordinate("�λ���", "�����ú���");
    tree.addSubordinate("IT����", "��������");
    tree.addSubordinate("IT����", "�۰�������");
    tree.addSubordinate("�����ú���", "��������");
    tree.addSubordinate("�����ú���", "ȫ������");
    tree.addSubordinate("�λ���", "�繫����");

    tree.preOrder(tree.root);
    std::cout << std::endl;
    tree.inOrder(tree.root);
    std::cout << std::endl;
    tree.postOrder(tree.root);
    std::cout << std::endl;

    tree.levelOrder(tree.root);

}