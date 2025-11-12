#include "MutantStack.hpp"

int	main( void )
{
	{
		std::cout << std::endl << MAGENTA "--- Subject Test: MutantStack<int, std::deque<int>> (Default) ---" RESET << std::endl;
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);

		std::cout << YELLOW "Top Element" RESET ": " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << YELLOW "Stack Size" RESET ": " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		std::cout << YELLOW "Stack" RESET ": ";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);
	}

	{
		std::cout << std::endl << MAGENTA "--- Test: std::list<int> (for comparison) ---" RESET << std::endl;
		std::list<int>	mlist;
		
		mlist.push_back(5);
		mlist.push_back(17);
		
		std::cout << YELLOW "Back Element" RESET ": " << mlist.back() << std::endl;
		
		mlist.pop_back();
		
		std::cout << YELLOW "List Size" RESET ": " << mlist.size() << std::endl;
		
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);
		
		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();
		
		++it;
		--it;
		std::cout << YELLOW "List" RESET ": ";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}


	{
		std::cout << std::endl << MAGENTA "--- Test: MutantStack<int, std::list<int>> ---" RESET << std::endl;
		MutantStack< int, std::list<int> > mstack_list;

		mstack_list.push(100);
		mstack_list.push(200);
		mstack_list.push(300);
		mstack_list.push(400);
		mstack_list.push(500);

		std::cout << YELLOW "Stack Size" RESET ": " << mstack_list.size() << std::endl;

		std::cout << YELLOW "Stack (List)" RESET ": ";
		MutantStack< int, std::list<int> >::iterator iter = mstack_list.begin();
		MutantStack< int, std::list<int> >::iterator iter_e = mstack_list.end();
		while (iter != iter_e)
			std::cout << *iter++ << " ";
		std::cout << std::endl;

		MutantStack< int, std::list<int> >::reverse_iterator riter = mstack_list.rbegin();
		MutantStack< int, std::list<int> >::reverse_iterator riter_e = mstack_list.rend();

		std::cout << YELLOW "Reverse Stack (List)" RESET ": ";
		while (riter != riter_e)
			std::cout << *riter++ << " ";
		std::cout << std::endl;
	}

	return (0);
}