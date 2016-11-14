''' 
Adds breakpoints in arduino code
'''

# Snippet of code that will initialize array of strings
# that contain lines the debugger will pause on
lines_snippet = 'char* DEBUG_LINES[] = {'

# Snippet inserted above each line that will be debugged
call_snippet = "DEBUG_FUNCTION();"


# Snippit of code for debugging function
function_snippet = """
void DEBUG_FUNCTION() {
	static int line_num = 0;
	Serial.println("Stopped at line: ");
	Serial.println(DEBUG_LINES[line_num++]);
	while (Serial.read() != 'n');
	if (line_num >= MAX_LINES) {
		line_num = 0;
	}
}
"""

#------------------------------------------------------------------------------
# Open the file, and store the code as a string
f = open('example_sketch/example_sketch.ino', 'r')
code = f.read()
f.close()

# parse code line by line
lines = code.splitlines()

# Line numbers where debug function call should be inserted
debug_locations = []
in_code = False

# Find lines to debug
for idx, line in enumerate(lines):
	if (line != ''):
		if in_code and (';' in line or '{' in line):
			debug_locations.append(idx)
			lines_snippet += '"' + str(idx) + ': ' + line + '",'
		if (line[0:13] == 'void loop() {'):
			in_code = True
		
lines_snippet += '};'

# Insert calls to DEBUG_FUNCTION
count = 0;
for i in debug_locations:
	lines.insert(i + count, call_snippet)
	count = count + 1

code = '\n'.join(lines)

code += '\n' + "int MAX_LINES = " + str(len(debug_locations)) + ";"
# add snippets to end of code
code += '\n' + lines_snippet + '\n' + function_snippet 

f = open('example_sketch/example_sketch.ino', 'w')
print code
f.write(code)
f.close()