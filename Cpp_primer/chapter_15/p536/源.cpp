//15_8
//��̬�����ڱ���ʱ������֪��,����������ʱ���߱��ʽ���ɵ�����
//��̬�����ڱ�������ȷ�����������Ǳ�������ʽ���ڴ����������������

//15_9
//��ʹ��һ���������������ʼ����Ի��ำֵʱ
struct base{
	int x;
};
struct foo:public base{
	int v;
};
foo a;
base *b = &a;

//15_10
//ifstream input(argv[1]);
//Sales_data total;
//read(input,total);
//read������һ���β�Ҫ��ΪfstreamΪifstream�Ļ���
//��������ifstream��ʼ����fstream����