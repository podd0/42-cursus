from datetime import datetime
from os import system
from constants import *

def template(filename):
	date = datetime.now().strftime("%Y/%m/%d %H:%M:%S")
	return f"""/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   {filename.ljust(50)} :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {USER42} <{USER42}@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: {date} by {USER42}            #+#    #+#             */
/*   Updated: {date} by {USER42}           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
"""
with open("pre_vector.h") as f:
	pre_vector_h = f.read().replace("NAME", "vi").replace("TYPE", "int")



with open("vector_body.h") as f:
	vector_h = ""
	s = f.read()
	for name, c_type in types.items():
		vector_h += s.replace("NAME", name).replace("TYPE", c_type)+'\n'

end_vector_h = "\n#endif\n"

with open("../libft/vector.h", "w") as f:
	f.write(template("vector.h")+pre_vector_h+vector_h+end_vector_h)
system("c_formatter_42 ../libft/vector.h")


sources = ["vector.c", "vector2.c"]
system("rm ../libft/vector/*")
for name, c_type in types.items():
	for i, source_file in enumerate(sources):
		with open(source_file) as f:
			source = f.read()
		out_file = f"{name}_{i}.c"
		with open("../libft/vector/"+out_file, "w") as f:
			f.write(template(out_file)+source.replace("TYPE", c_type).replace("NAME", name))
		system("c_formatter_42 ../libft/vector/"+out_file)


