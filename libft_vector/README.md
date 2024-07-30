# Generate generic vectors
This is a generic c++ like \<vector\>, made for 42 school.
It's not a project, and it works gets added to libft.

## Requirements
- python3
- c_formatter_42  

#### Included, but you might want to change these:
- libft
- a function `safe_alloc(int n_bytes)` that checks for malloc fails in your libft
## Usage
```
cd vector_gen
vi constants.py 
```
`constants.py` contains your user and a dictionary of (name:type) entries.
the name is the name of the vector of that type; for example if there's a pair
`"vi":"int"` the struct s_vi typedef to t_vi will have type int.  
You have to set your username and the types dictionary, then you can build your libft+vector
```
python3 gen.py
cd ../libft
make
```
