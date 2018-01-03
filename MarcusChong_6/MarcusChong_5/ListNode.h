
template <typename E>
class ListNode 
{
	public:
		E data;
		ListNode<E> *next;
		ListNode<E> *prev;

		ListNode()
		{

		}
		~ListNode()
		{
			if(next != NULL)
				delete next;
		}

		ListNode(E d)
		{
			data = d;
			next = NULL;
			prev = NULL;
		}
		
};
