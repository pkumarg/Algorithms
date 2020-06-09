class Search {
    public:
	template <typename TYPE> static size_t linearSearch(
		TYPE *list, size_t size, TYPE element) {

	    for(size_t iter = 0; iter < size; iter++) {
		if(list[iter] == element)
		    return iter;
	    }

	    return std::string::npos;
	}
};
