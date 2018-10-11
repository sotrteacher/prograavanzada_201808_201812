template <typename Item_Type>
std::ostream& operator<<(std::ostream& out,
	const std::set<Item_Type>& a_set) {
	out << "{";
	bool first = true;
	for (typename std::set<Item_Type>::const_iterator 
		itr=a_set.begin(); itr!= a_set.end(); ++itr)
	{
		if (first) {
			out << *itr;
		}
		else {
			out << ", " << *itr;
		}
		first = false;
	}
	return out << "}";
}