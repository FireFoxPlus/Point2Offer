//翻转单词顺序VS左旋转字符串
//题目一：输入一个英文句子，翻转句子中单词的顺序，但单词内字符顺序不变。
//简单起见，标点符号海瑞普通字母一样处理
//题目二：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
//定义一个函数完成左旋转操作
class Pro42
{
public :
    char *reverseSenten(char *val);
    void reverseWord(char *val , int length);
    void leftReverse(char *val , int length , int left);
};
