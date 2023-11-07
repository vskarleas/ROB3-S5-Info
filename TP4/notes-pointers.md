# Pointers Notes

## Function Pointer in C

### Overview

**Function pointers** in C are variables that can store the memory address of functions and can be used in a program to create a function call to functions pointed by them. Function pointers in C need to be declared with an asterisk symbol and function parameters (same as the function they will point to) before using them in the program. Declaration of function pointers in C includes the return type and data type of different function arguments.

An** **asterisk symbol** **before the pointer name differentiates the function pointer from a usual function declaration. Functions can aspect function pointer as a function argument and later call it inside the function body. Such passed functions are called** **callback functions.

### Introduction

A block of memory is reserved by the compiler when we declare a variable. To store these memory addresses, C allows programmers to use the concept of pointers that can hold the address of any other data type. Pointers can be de-referenced using the** ****asterisk** ***** operator to get the value stored in an address. Like variables, instructions of a function are also stored in memory and have an address. A pointer pointing to the address of a function is called** ** **function pointer** . A function pointer in C can be used to create function calls to the function they point to just like a normal function.

In those notes, we will understand how function pointers in C are declared and can be used to create calls to the function to which they point. We will also understand how we can create an array of function pointers in C and how a function can be passed to another function as an argument with the help of function pointers. In the end, we will discuss how pointers are passed and returned from user-defined functions. Before jumping to function pointers let us see through an example of how functions have a memory address like variables.

<pre data-reader-unique-id="15"><div data-reader-unique-id="16"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="17"><code data-reader-unique-id="18"><span data-reader-unique-id="19">#</span><span data-reader-unique-id="20">include</span><span data-reader-unique-id="21"></span><span data-reader-unique-id="22"><stdio.h></span><span data-reader-unique-id="23">
</span>
<span data-reader-unique-id="24"></span><span data-reader-unique-id="25">void</span><span data-reader-unique-id="26"></span><span data-reader-unique-id="27">test</span><span data-reader-unique-id="28">()</span><span data-reader-unique-id="29"></span><span data-reader-unique-id="30">{
</span><span data-reader-unique-id="31"></span><span data-reader-unique-id="32">// test function that does nothing</span><span data-reader-unique-id="33">
</span><span data-reader-unique-id="34"></span><span data-reader-unique-id="35">return</span><span data-reader-unique-id="36"> ;
</span>}

<span data-reader-unique-id="37"></span><span data-reader-unique-id="38">int</span><span data-reader-unique-id="39"></span><span data-reader-unique-id="40">main</span><span data-reader-unique-id="41">()</span><span data-reader-unique-id="42"></span><span data-reader-unique-id="43">{
</span><span data-reader-unique-id="44"></span><span data-reader-unique-id="45">int</span><span data-reader-unique-id="46"> a = </span><span data-reader-unique-id="47">5</span><span data-reader-unique-id="48">;
</span><span data-reader-unique-id="49"></span><span data-reader-unique-id="50">// printing the address of variable a</span><span data-reader-unique-id="51">
</span><span data-reader-unique-id="52"></span><span data-reader-unique-id="53">printf</span><span data-reader-unique-id="54">(</span><span data-reader-unique-id="55">"Address of variable = %p\n"</span><span data-reader-unique-id="56">, &a);
</span>  
<span data-reader-unique-id="57"></span><span data-reader-unique-id="58">// printing the address of function main()</span><span data-reader-unique-id="59">
</span><span data-reader-unique-id="60"></span><span data-reader-unique-id="61">printf</span><span data-reader-unique-id="62">(</span><span data-reader-unique-id="63">"Address of a function = %p"</span><span data-reader-unique-id="64">, test);
</span><span data-reader-unique-id="65"></span><span data-reader-unique-id="66">return</span><span data-reader-unique-id="67"></span><span data-reader-unique-id="68">0</span><span data-reader-unique-id="69">;
</span>}
</code></pre></div></div></pre>

**Output**

<pre data-reader-unique-id="72"><div data-reader-unique-id="73"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="74"><code data-reader-unique-id="75"><span data-reader-unique-id="76">Address of variable = </span><span data-reader-unique-id="77">0x7ffd7f36a224</span><span data-reader-unique-id="78">
</span><span data-reader-unique-id="79">Address of a function = </span><span data-reader-unique-id="80">0x55f8e8abb169</span><span data-reader-unique-id="81">
</span></code></pre></div></div></pre>

From this example, we can observe that just like a variable has an address in memory, our function** **test()** **also has an address. Now that we have confirmed that functions reside in memory and have a unique address, let us see how we can use a pointer to store its address and create function calls.

### Declaring a Function Pointer in C

Now that we know that functions have a unique memory address, we can use function pointers in C that can point to the first executable code inside a function body.

![Declaring a function pointer](https://scaler.com/topics/images/declaring_a_function_pointer.webp)

For example, in the above figure we have a function** **add()** **to add two integer numbers. Here, the function name points to the address of the function itself so we are using a function pointer** **fptr** **that stores the address of beginning of the function** **add(a, b)** **that in 1001 in this case.

Before using a function pointer we need to declare them to tell the compiler the type of function a pointer can point to. The general syntax of a function pointer is,

### Syntax of Function Pointer in C

<pre data-reader-unique-id="245"><div data-reader-unique-id="246"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="247"><code data-reader-unique-id="248"><span data-reader-unique-id="249">return_type (* pointer_name) (datatype_arg_1, datatype_arg_1, ...);
</span></code></pre></div></div></pre>

Declaring a function pointer in C is comparable to declaring a function except that when a function pointer is declared, we** ****prefix its name which is an Asterisk** *** **symbol.

For example, if a function has the declaration

Declaration of a function pointer in C for the function** **foo** **will be

<pre data-reader-unique-id="270"><div data-reader-unique-id="271"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="272"><code data-reader-unique-id="273"><span data-reader-unique-id="274">// function pointer declaration</span><span data-reader-unique-id="275">
</span><span data-reader-unique-id="276"></span><span data-reader-unique-id="277">float</span><span data-reader-unique-id="278"> (*foo_pointer) (</span><span data-reader-unique-id="279">int</span><span data-reader-unique-id="280">, </span><span data-reader-unique-id="281">int</span><span data-reader-unique-id="282">);
</span>
<span data-reader-unique-id="283"></span><span data-reader-unique-id="284">/*
</span><span data-reader-unique-id="285">assigning the address of the function (foo)
</span><span data-reader-unique-id="286">to function pointer
</span><span data-reader-unique-id="287">*/</span><span data-reader-unique-id="288">
</span>foo_pointer = foo;
</code></pre></div></div></pre>

Here, pointer** ***foo_pointer** **is a function pointer and stores the memory address of a function** **foo** **that takes two arguments of type** **int** **and returns a value of data type** **float.

### Tricky example

<pre data-reader-unique-id="307"><div data-reader-unique-id="308"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="309"><code data-reader-unique-id="310"><span data-reader-unique-id="311">void</span><span data-reader-unique-id="312"> *(*fp) (</span><span data-reader-unique-id="313">int</span><span data-reader-unique-id="314"> *, </span><span data-reader-unique-id="315">int</span><span data-reader-unique-id="316"> *);
</span></code></pre></div></div></pre>

At first glance, this example seems complex but the trick to understanding such declarations is to read them inside out. Here,** **(*fp)** **is a function pointer just like normal pointer in C like** **int *ptr. This function pointer** **(*fp)** **can point to functions with two** **int *** **type arguments and has a return type of** **void *** **as we can see from its declaration where** **(int *, int *)** **explains the type and number of arguments ans** **void *** **is the return type from the pointed function.

 **Note** : It is important to declare a function before assigning its address to a function pointer in C.

### Calling a Function Through a Function Pointer in C

Calling a function using a pointer is similar to calling a function in the usual way using the name of the function.

Suppose we declare a function and its pointer as given below.

<pre data-reader-unique-id="331"><div data-reader-unique-id="332"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="333"><code data-reader-unique-id="334"><span data-reader-unique-id="335">int</span><span data-reader-unique-id="336"> (*pointer) (</span><span data-reader-unique-id="337">int</span><span data-reader-unique-id="338">); </span><span data-reader-unique-id="339">// function pointer declaration</span><span data-reader-unique-id="340">
</span><span data-reader-unique-id="341"></span><span data-reader-unique-id="342">int</span><span data-reader-unique-id="343"></span><span data-reader-unique-id="344">areaSquare</span><span data-reader-unique-id="345"></span><span data-reader-unique-id="346">(</span><span data-reader-unique-id="347">int</span><span data-reader-unique-id="348">)</span><span data-reader-unique-id="349">; </span><span data-reader-unique-id="350">// function declaration</span><span data-reader-unique-id="351">
</span>pointer = areaSquare;
</code></pre></div></div></pre>

To call the function** **areaSquare, we can create a function call using any of the three ways

<pre data-reader-unique-id="354"><div data-reader-unique-id="355"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="356"><code data-reader-unique-id="357"><span data-reader-unique-id="358">int</span><span data-reader-unique-id="359"> length = </span><span data-reader-unique-id="360">5</span><span data-reader-unique-id="361">;
</span>
<span data-reader-unique-id="362"></span><span data-reader-unique-id="363">// Different ways to call the function</span><span data-reader-unique-id="364">
</span>
<span data-reader-unique-id="365"></span><span data-reader-unique-id="366">// 1. using function name</span><span data-reader-unique-id="367">
</span><span data-reader-unique-id="368"></span><span data-reader-unique-id="369">int</span><span data-reader-unique-id="370"> area = areaSquare(length);
</span>
<span data-reader-unique-id="371"></span><span data-reader-unique-id="372">// 2. using function pointer (a)</span><span data-reader-unique-id="373">
</span><span data-reader-unique-id="374"></span><span data-reader-unique-id="375">int</span><span data-reader-unique-id="376"> area = (*pointer)(length);
</span>
<span data-reader-unique-id="377"></span><span data-reader-unique-id="378">// 3. using function pointer (b)</span><span data-reader-unique-id="379">
</span><span data-reader-unique-id="380"></span><span data-reader-unique-id="381">int</span><span data-reader-unique-id="382"> area = pointer(length);
</span></code></pre></div></div></pre>

The effect of calling functions using pointers or using their name is the same. It is not compulsory to call the function with the indirection operator** **(*)** **as shown in the second case but it is good practice to use the indirection operator to clear out that function is called using a pointer as** **(*pointer)()** **is more readable when compared to calling function from pointers with parentheses** **pointer().

### Example for Function Pointer in C

Now that we know the syntax of how function pointers in C are declared and used to create a function call. Let us see an example where we are creating a function pointer to call the function that returns the area of a rectangle.

<pre data-reader-unique-id="390"><div data-reader-unique-id="391"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="392"><code data-reader-unique-id="393"><span data-reader-unique-id="394">#</span><span data-reader-unique-id="395">include</span><span data-reader-unique-id="396"><stdio.h></span><span data-reader-unique-id="397">
</span>
<span data-reader-unique-id="398"></span><span data-reader-unique-id="399">// function declaration</span><span data-reader-unique-id="400">
</span><span data-reader-unique-id="401"></span><span data-reader-unique-id="402">int</span><span data-reader-unique-id="403"></span><span data-reader-unique-id="404">areaRectangle</span><span data-reader-unique-id="405">(</span><span data-reader-unique-id="406">int</span><span data-reader-unique-id="407">, </span><span data-reader-unique-id="408">int</span><span data-reader-unique-id="409">)</span><span data-reader-unique-id="410">;
</span>
<span data-reader-unique-id="411"></span><span data-reader-unique-id="412">int</span><span data-reader-unique-id="413"></span><span data-reader-unique-id="414">main</span><span data-reader-unique-id="415">()</span><span data-reader-unique-id="416"></span><span data-reader-unique-id="417">{
</span><span data-reader-unique-id="418"></span><span data-reader-unique-id="419">int</span><span data-reader-unique-id="420"> length, breadth, area;
</span>  
<span data-reader-unique-id="421"></span><span data-reader-unique-id="422">// function pointer declaration</span><span data-reader-unique-id="423">
</span><span data-reader-unique-id="424"></span><span data-reader-unique-id="425">// note that our pointer declaration has identical </span><span data-reader-unique-id="426">
</span><span data-reader-unique-id="427"></span><span data-reader-unique-id="428">// arguments as the function it will point to</span><span data-reader-unique-id="429">
</span><span data-reader-unique-id="430"></span><span data-reader-unique-id="431">int</span><span data-reader-unique-id="432"> (*fp)(</span><span data-reader-unique-id="433">int</span><span data-reader-unique-id="434">, </span><span data-reader-unique-id="435">int</span><span data-reader-unique-id="436">); 
</span>  
<span data-reader-unique-id="437"></span><span data-reader-unique-id="438">printf</span><span data-reader-unique-id="439">(</span><span data-reader-unique-id="440">"Enter length and breadth of a rectangle\n"</span><span data-reader-unique-id="441">);
</span><span data-reader-unique-id="442"></span><span data-reader-unique-id="443">scanf</span><span data-reader-unique-id="444">(</span><span data-reader-unique-id="445">"%d%d"</span><span data-reader-unique-id="446">, &length, &breadth);
</span>  
<span data-reader-unique-id="447"></span><span data-reader-unique-id="448">// pointing the pointer to functions memory address</span><span data-reader-unique-id="449">
</span>    fp = areaRectangle;
  
<span data-reader-unique-id="450"></span><span data-reader-unique-id="451">// calling the function using function pointer</span><span data-reader-unique-id="452">
</span>    area = (*fp)(length, breadth); 
  
<span data-reader-unique-id="453"></span><span data-reader-unique-id="454">printf</span><span data-reader-unique-id="455">(</span><span data-reader-unique-id="456">"Area of rectangle = %d"</span><span data-reader-unique-id="457">, area);
</span><span data-reader-unique-id="458"></span><span data-reader-unique-id="459">return</span><span data-reader-unique-id="460"></span><span data-reader-unique-id="461">0</span><span data-reader-unique-id="462">;
</span>}

<span data-reader-unique-id="463"></span><span data-reader-unique-id="464">// function definition </span><span data-reader-unique-id="465">
</span><span data-reader-unique-id="466"></span><span data-reader-unique-id="467">int</span><span data-reader-unique-id="468"></span><span data-reader-unique-id="469">areaRectangle</span><span data-reader-unique-id="470">(</span><span data-reader-unique-id="471">int</span><span data-reader-unique-id="472"> l, </span><span data-reader-unique-id="473">int</span><span data-reader-unique-id="474"> b)</span><span data-reader-unique-id="475"></span><span data-reader-unique-id="476">{
</span><span data-reader-unique-id="477"></span><span data-reader-unique-id="478">int</span><span data-reader-unique-id="479"> area_of_rectangle = l * b;
</span><span data-reader-unique-id="480"></span><span data-reader-unique-id="481">return</span><span data-reader-unique-id="482"> area_of_rectangle;
</span>}
</code></pre></div></div></pre>

**Output**

<pre data-reader-unique-id="485"><div data-reader-unique-id="486"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="487"><code data-reader-unique-id="488"><span data-reader-unique-id="489">Enter length </span><span data-reader-unique-id="490">and</span><span data-reader-unique-id="491"> breadth of a rectangle
</span><span data-reader-unique-id="492"></span><span data-reader-unique-id="493">5</span><span data-reader-unique-id="494"></span><span data-reader-unique-id="495">9</span><span data-reader-unique-id="496">
</span><span data-reader-unique-id="497">Area of rectangle = </span><span data-reader-unique-id="498">45</span><span data-reader-unique-id="499">
</span></code></pre></div></div></pre>

Here, we have defined a function** **areaRectangle()** **that takes two integer inputs and returns the area of the rectangle. To store the reference of the function, we are using function pointer** **(*fp)** **that has a similar declaration to the function it points to. To point the function address to the pointer we don't need to use** **&symbol as the function name** **areaRectangle** **also represents the function's address. To call the function, we pass parameters inside the parenthesis ((*fp)(length, breadth)), and the return value is stored in the variable** **area.

#### Example: Array of function pointers

Arrays are data structure that stores collection of identical data types. Like any other data types we can create an array to store function pointers in C. Function pointers can be accessed from their indexes like we access normal array values** **arr[i]. This way we are creating an array of function pointers, where each array element stores a function pointer pointing to different functions.

This approach is useful when we do not know in advance which function is called, as shown in the example.

<pre data-reader-unique-id="511"><div data-reader-unique-id="512"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="513"><code data-reader-unique-id="514"><span data-reader-unique-id="515">#</span><span data-reader-unique-id="516">include</span><span data-reader-unique-id="517"><stdio.h></span><span data-reader-unique-id="518">
</span>
<span data-reader-unique-id="519"></span><span data-reader-unique-id="520">float</span><span data-reader-unique-id="521"></span><span data-reader-unique-id="522">add</span><span data-reader-unique-id="523">(</span><span data-reader-unique-id="524">int</span><span data-reader-unique-id="525">, </span><span data-reader-unique-id="526">int</span><span data-reader-unique-id="527">)</span><span data-reader-unique-id="528">;
</span><span data-reader-unique-id="529"></span><span data-reader-unique-id="530">float</span><span data-reader-unique-id="531"></span><span data-reader-unique-id="532">multiply</span><span data-reader-unique-id="533">(</span><span data-reader-unique-id="534">int</span><span data-reader-unique-id="535">,</span><span data-reader-unique-id="536">int</span><span data-reader-unique-id="537">)</span><span data-reader-unique-id="538">;
</span><span data-reader-unique-id="539"></span><span data-reader-unique-id="540">float</span><span data-reader-unique-id="541"></span><span data-reader-unique-id="542">divide</span><span data-reader-unique-id="543">(</span><span data-reader-unique-id="544">int</span><span data-reader-unique-id="545">,</span><span data-reader-unique-id="546">int</span><span data-reader-unique-id="547">)</span><span data-reader-unique-id="548">;
</span><span data-reader-unique-id="549"></span><span data-reader-unique-id="550">float</span><span data-reader-unique-id="551"></span><span data-reader-unique-id="552">subtract</span><span data-reader-unique-id="553">(</span><span data-reader-unique-id="554">int</span><span data-reader-unique-id="555">,</span><span data-reader-unique-id="556">int</span><span data-reader-unique-id="557">)</span><span data-reader-unique-id="558">;
</span>
<span data-reader-unique-id="559"></span><span data-reader-unique-id="560">int</span><span data-reader-unique-id="561"></span><span data-reader-unique-id="562">main</span><span data-reader-unique-id="563">()</span><span data-reader-unique-id="564"></span><span data-reader-unique-id="565">{
</span><span data-reader-unique-id="566"></span><span data-reader-unique-id="567">int</span><span data-reader-unique-id="568"> a, b;
</span><span data-reader-unique-id="569"></span><span data-reader-unique-id="570">float</span><span data-reader-unique-id="571"> (*operation[</span><span data-reader-unique-id="572">4</span><span data-reader-unique-id="573">])(</span><span data-reader-unique-id="574">int</span><span data-reader-unique-id="575">, </span><span data-reader-unique-id="576">int</span><span data-reader-unique-id="577">);
</span>
<span data-reader-unique-id="578">    operation[</span><span data-reader-unique-id="579">0</span><span data-reader-unique-id="580">] = add;
</span><span data-reader-unique-id="581">    operation[</span><span data-reader-unique-id="582">1</span><span data-reader-unique-id="583">] = subtract;
</span><span data-reader-unique-id="584">    operation[</span><span data-reader-unique-id="585">2</span><span data-reader-unique-id="586">] = multiply;
</span><span data-reader-unique-id="587">    operation[</span><span data-reader-unique-id="588">3</span><span data-reader-unique-id="589">] = divide;
</span>  
<span data-reader-unique-id="590"></span><span data-reader-unique-id="591">printf</span><span data-reader-unique-id="592">(</span><span data-reader-unique-id="593">"Enter two values "</span><span data-reader-unique-id="594">);
</span><span data-reader-unique-id="595"></span><span data-reader-unique-id="596">scanf</span><span data-reader-unique-id="597">(</span><span data-reader-unique-id="598">"%d%d"</span><span data-reader-unique-id="599">, &a, &b);
</span>  
<span data-reader-unique-id="600"></span><span data-reader-unique-id="601">float</span><span data-reader-unique-id="602"> result = (*operation[</span><span data-reader-unique-id="603">0</span><span data-reader-unique-id="604">])(a, b);
</span><span data-reader-unique-id="605"></span><span data-reader-unique-id="606">printf</span><span data-reader-unique-id="607">(</span><span data-reader-unique-id="608">"Addition (a+b) = %.1f\n"</span><span data-reader-unique-id="609">, result);
</span>  
<span data-reader-unique-id="610">    result = (*operation[</span><span data-reader-unique-id="611">1</span><span data-reader-unique-id="612">])(a, b);
</span><span data-reader-unique-id="613"></span><span data-reader-unique-id="614">printf</span><span data-reader-unique-id="615">(</span><span data-reader-unique-id="616">"Subtraction (a-b) = %.1f\n"</span><span data-reader-unique-id="617">, result);
</span>  
<span data-reader-unique-id="618">    result = (*operation[</span><span data-reader-unique-id="619">2</span><span data-reader-unique-id="620">])(a, b);
</span><span data-reader-unique-id="621"></span><span data-reader-unique-id="622">printf</span><span data-reader-unique-id="623">(</span><span data-reader-unique-id="624">"Multiplication (a*b) = %.1f\n"</span><span data-reader-unique-id="625">, result);
</span>  
<span data-reader-unique-id="626">    result = (*operation[</span><span data-reader-unique-id="627">3</span><span data-reader-unique-id="628">])(a, b);
</span><span data-reader-unique-id="629"></span><span data-reader-unique-id="630">printf</span><span data-reader-unique-id="631">(</span><span data-reader-unique-id="632">"Division (a/b) = %.1f\n"</span><span data-reader-unique-id="633">, result);
</span>  
<span data-reader-unique-id="634"></span><span data-reader-unique-id="635">return</span><span data-reader-unique-id="636"></span><span data-reader-unique-id="637">0</span><span data-reader-unique-id="638">;
</span>}

<span data-reader-unique-id="639"></span><span data-reader-unique-id="640">float</span><span data-reader-unique-id="641"></span><span data-reader-unique-id="642">add</span><span data-reader-unique-id="643">(</span><span data-reader-unique-id="644">int</span><span data-reader-unique-id="645"> a, </span><span data-reader-unique-id="646">int</span><span data-reader-unique-id="647"> b)</span><span data-reader-unique-id="648"></span><span data-reader-unique-id="649">{
</span><span data-reader-unique-id="650"></span><span data-reader-unique-id="651">return</span><span data-reader-unique-id="652"> a + b;
</span>}

<span data-reader-unique-id="653"></span><span data-reader-unique-id="654">float</span><span data-reader-unique-id="655"></span><span data-reader-unique-id="656">subtract</span><span data-reader-unique-id="657">(</span><span data-reader-unique-id="658">int</span><span data-reader-unique-id="659"> a, </span><span data-reader-unique-id="660">int</span><span data-reader-unique-id="661"> b)</span><span data-reader-unique-id="662"></span><span data-reader-unique-id="663">{
</span><span data-reader-unique-id="664"></span><span data-reader-unique-id="665">return</span><span data-reader-unique-id="666"> a - b;
</span>}

<span data-reader-unique-id="667"></span><span data-reader-unique-id="668">float</span><span data-reader-unique-id="669"></span><span data-reader-unique-id="670">multiply</span><span data-reader-unique-id="671">(</span><span data-reader-unique-id="672">int</span><span data-reader-unique-id="673"> a, </span><span data-reader-unique-id="674">int</span><span data-reader-unique-id="675"> b)</span><span data-reader-unique-id="676"></span><span data-reader-unique-id="677">{
</span><span data-reader-unique-id="678"></span><span data-reader-unique-id="679">return</span><span data-reader-unique-id="680"> a * b;
</span>}

<span data-reader-unique-id="681"></span><span data-reader-unique-id="682">float</span><span data-reader-unique-id="683"></span><span data-reader-unique-id="684">divide</span><span data-reader-unique-id="685">(</span><span data-reader-unique-id="686">int</span><span data-reader-unique-id="687"> a, </span><span data-reader-unique-id="688">int</span><span data-reader-unique-id="689"> b)</span><span data-reader-unique-id="690"></span><span data-reader-unique-id="691">{
</span><span data-reader-unique-id="692"></span><span data-reader-unique-id="693">return</span><span data-reader-unique-id="694"> a / (b * </span><span data-reader-unique-id="695">1.0</span><span data-reader-unique-id="696">);
</span>}
</code></pre></div></div></pre>

**Output**

<pre data-reader-unique-id="699"><div data-reader-unique-id="700"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="701"><code data-reader-unique-id="702"><span data-reader-unique-id="703">Enter two values </span><span data-reader-unique-id="704">3</span><span data-reader-unique-id="705"></span><span data-reader-unique-id="706">2</span><span data-reader-unique-id="707">
</span><span data-reader-unique-id="708">Addition (a+b) = </span><span data-reader-unique-id="709">5.0</span><span data-reader-unique-id="710">
</span><span data-reader-unique-id="711">Subtraction (a-b) = </span><span data-reader-unique-id="712">1.0</span><span data-reader-unique-id="713">
</span><span data-reader-unique-id="714">Multiplication (a*b) = </span><span data-reader-unique-id="715">6.0</span><span data-reader-unique-id="716">
</span><span data-reader-unique-id="717">Division (a/b) = </span><span data-reader-unique-id="718">1.5</span><span data-reader-unique-id="719">
</span></code></pre></div></div></pre>

Here, we have stored the addresses of four functions in an array of function pointers. We used this array to call the required function using the function pointer stored in this array.

### Functions Using Pointer Variables

C allows pointers to be passed in as function arguments and also returns pointers from the function. To pass pointers in the function, we simply declare the function parameter as** ** **pointer type** . When functions have their pointer type arguments, the changes made on them inside the function persist even after program exists function scope because the changes are made on the actual address pointed by the pointer. This approach to pass arguments to a function is called as** ****pass by reference** because as shown in the figure below reference of the variable is passed to the function instead of the value stored in the address.

![Function using Pointer Variables](https://scaler.com/topics/images/function_using_pointers.webp)

Extra care should be taken when function is used to return pointers because local variables don't live outside the function scope and if they are returned as pointers from function then that pointer will point to nothing when function terminates.

For example,

<pre data-reader-unique-id="730"><div data-reader-unique-id="731"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="732"><code data-reader-unique-id="733"><span data-reader-unique-id="734">#</span><span data-reader-unique-id="735">include</span><span data-reader-unique-id="736"><stdio.h></span><span data-reader-unique-id="737">
</span>
<span data-reader-unique-id="738"></span><span data-reader-unique-id="739">int</span><span data-reader-unique-id="740">* </span><span data-reader-unique-id="741">increment</span><span data-reader-unique-id="742">(</span><span data-reader-unique-id="743">int</span><span data-reader-unique-id="744"> a)</span><span data-reader-unique-id="745"></span><span data-reader-unique-id="746">{
</span><span data-reader-unique-id="747"></span><span data-reader-unique-id="748">int</span><span data-reader-unique-id="749"> *b;
</span>    *b = a;
<span data-reader-unique-id="750">    *b += </span><span data-reader-unique-id="751">1</span><span data-reader-unique-id="752">; </span><span data-reader-unique-id="753">// incrementing the value</span><span data-reader-unique-id="754">
</span>  
<span data-reader-unique-id="755"></span><span data-reader-unique-id="756">return</span><span data-reader-unique-id="757"> b; </span><span data-reader-unique-id="758">// returning pointer from the function</span><span data-reader-unique-id="759">
</span>}

<span data-reader-unique-id="760"></span><span data-reader-unique-id="761">int</span><span data-reader-unique-id="762"></span><span data-reader-unique-id="763">main</span><span data-reader-unique-id="764">()</span><span data-reader-unique-id="765"></span><span data-reader-unique-id="766">{
</span><span data-reader-unique-id="767"></span><span data-reader-unique-id="768">int</span><span data-reader-unique-id="769"> num = </span><span data-reader-unique-id="770">5</span><span data-reader-unique-id="771">;
</span>  
<span data-reader-unique-id="772"></span><span data-reader-unique-id="773">int</span><span data-reader-unique-id="774"> *b = increment(num);
</span><span data-reader-unique-id="775"></span><span data-reader-unique-id="776">printf</span><span data-reader-unique-id="777">(</span><span data-reader-unique-id="778">"Incremented value = %d"</span><span data-reader-unique-id="779">, *b);
</span>
<span data-reader-unique-id="780"></span><span data-reader-unique-id="781">return</span><span data-reader-unique-id="782"></span><span data-reader-unique-id="783">0</span><span data-reader-unique-id="784">;
</span>}
</code></pre></div></div></pre>

In this case, the compiler throws** ****segmentation fault** error because you are returning a copy of a pointer to a local variable. However, that local variable is de-allocated when the function** **increment** **finishes, so when we try to access it afterwards compiler is not able to reference the pointer.

#### Safe ways to return a pointer from a function

1. Return variables are either created using the keyword static or created dynamically at run time because such variables exist in memory beyond the scope of the called function.
2. Use arguments that are passed by their reference because such functions exist in the calling function scope.

#### Example: Passing and returning values from functions using pointer in C

<pre data-reader-unique-id="793"><div data-reader-unique-id="794"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="795"><code data-reader-unique-id="796"><span data-reader-unique-id="797">#</span><span data-reader-unique-id="798">include</span><span data-reader-unique-id="799"><stdio.h></span><span data-reader-unique-id="800">
</span>
<span data-reader-unique-id="801"></span><span data-reader-unique-id="802">int</span><span data-reader-unique-id="803"> *</span><span data-reader-unique-id="804">larger</span><span data-reader-unique-id="805">(</span><span data-reader-unique-id="806">int</span><span data-reader-unique-id="807"> *, </span><span data-reader-unique-id="808">int</span><span data-reader-unique-id="809"> *)</span><span data-reader-unique-id="810">;
</span>
<span data-reader-unique-id="811"></span><span data-reader-unique-id="812">int</span><span data-reader-unique-id="813"></span><span data-reader-unique-id="814">main</span><span data-reader-unique-id="815">()</span><span data-reader-unique-id="816"></span><span data-reader-unique-id="817">{
</span><span data-reader-unique-id="818"></span><span data-reader-unique-id="819">int</span><span data-reader-unique-id="820"> a = </span><span data-reader-unique-id="821">10</span><span data-reader-unique-id="822">, b = </span><span data-reader-unique-id="823">15</span><span data-reader-unique-id="824">;
</span><span data-reader-unique-id="825"></span><span data-reader-unique-id="826">int</span><span data-reader-unique-id="827"> *greater;
</span><span data-reader-unique-id="828"></span><span data-reader-unique-id="829">// passing address of variables to function</span><span data-reader-unique-id="830">
</span>    greater = larger(&a, &b);
<span data-reader-unique-id="831"></span><span data-reader-unique-id="832">printf</span><span data-reader-unique-id="833">(</span><span data-reader-unique-id="834">"Larger value = %d"</span><span data-reader-unique-id="835">, *greater);
</span><span data-reader-unique-id="836"></span><span data-reader-unique-id="837">return</span><span data-reader-unique-id="838"></span><span data-reader-unique-id="839">0</span><span data-reader-unique-id="840">;
</span>}

<span data-reader-unique-id="841"></span><span data-reader-unique-id="842">int</span><span data-reader-unique-id="843"> *</span><span data-reader-unique-id="844">larger</span><span data-reader-unique-id="845">(</span><span data-reader-unique-id="846">int</span><span data-reader-unique-id="847"> *a, </span><span data-reader-unique-id="848">int</span><span data-reader-unique-id="849"> *b)</span><span data-reader-unique-id="850"></span><span data-reader-unique-id="851">{
</span><span data-reader-unique-id="852"></span><span data-reader-unique-id="853">if</span><span data-reader-unique-id="854"> (*a > *b) {
</span><span data-reader-unique-id="855"></span><span data-reader-unique-id="856">return</span><span data-reader-unique-id="857"> a;
</span>    }
<span data-reader-unique-id="858"></span><span data-reader-unique-id="859">// returning address of greater value</span><span data-reader-unique-id="860">
</span><span data-reader-unique-id="861"></span><span data-reader-unique-id="862">return</span><span data-reader-unique-id="863"> b;
</span>}

</code></pre></div></div></pre>

**Output**

### Referencing and Dereferencing of Function Pointer in C

Suppose we want to create a sorting function. It makes more sense to allow the function’s caller to decide the order in which values are sorted (ascending, descending, etc). One way is to provide a flag in the function argument to decide what to do, but this is not flexible.

Another way is to provide user flexibility to pass a function in our sort function. This function can take two values as input and perform a comparison between them. A syntax for our new function will look like.

<pre data-reader-unique-id="877"><div data-reader-unique-id="878"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="879"><code data-reader-unique-id="880"><span data-reader-unique-id="881">void</span><span data-reader-unique-id="882"></span><span data-reader-unique-id="883">sort</span><span data-reader-unique-id="884">(</span><span data-reader-unique-id="885">int</span><span data-reader-unique-id="886"></span><span data-reader-unique-id="887">array</span><span data-reader-unique-id="888">[], </span><span data-reader-unique-id="889">int</span><span data-reader-unique-id="890"> n, function comparison)</span><span data-reader-unique-id="891">;
</span></code></pre></div></div></pre>

![Refrencing And Defrencing of Function Pointer](https://scaler.com/topics/images/refrencing_and_derefrencing.webp)

For example, if we want to sort an array in decreasing order a comparison function can be used as shown in figure and the function can be passed to the sorting function using function pointers.

As shown in the example we can pass functions in another function as an argument using function pointers. This way we can** ** **pass reference of function pointer in a function and dereference it later inside the function's body to create a function call** .

Let us look at some examples to understand the uses of function pointers.

#### Example: Function pointer passed as an argument

Another way to use function pointers is by passing them to other functions as a function argument. We also call such functions as** ****callback functions** because receiving function** ** *calls them back* .

<pre data-reader-unique-id="902"><div data-reader-unique-id="903"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="904"><code data-reader-unique-id="905"><span data-reader-unique-id="906">#</span><span data-reader-unique-id="907">include</span><span data-reader-unique-id="908"><stdio.h></span><span data-reader-unique-id="909">
</span>
<span data-reader-unique-id="910"></span><span data-reader-unique-id="911">int</span><span data-reader-unique-id="912"></span><span data-reader-unique-id="913">conditionalSum</span><span data-reader-unique-id="914">(</span><span data-reader-unique-id="915">int</span><span data-reader-unique-id="916"> a, </span><span data-reader-unique-id="917">int</span><span data-reader-unique-id="918"> b,</span><span data-reader-unique-id="919">int</span><span data-reader-unique-id="920"> (*ptr)())</span><span data-reader-unique-id="921"></span><span data-reader-unique-id="922">{
</span><span data-reader-unique-id="923"></span><span data-reader-unique-id="924">// modify the arguments according to the condition </span><span data-reader-unique-id="925">
</span><span data-reader-unique-id="926"></span><span data-reader-unique-id="927">// of the function ptr points to</span><span data-reader-unique-id="928">
</span>    a = (*ptr)(a);
    b = (*ptr)(b);

<span data-reader-unique-id="929"></span><span data-reader-unique-id="930">return</span><span data-reader-unique-id="931"> a + b;
</span>}

<span data-reader-unique-id="932"></span><span data-reader-unique-id="933">int</span><span data-reader-unique-id="934"></span><span data-reader-unique-id="935">square</span><span data-reader-unique-id="936">(</span><span data-reader-unique-id="937">int</span><span data-reader-unique-id="938"> a)</span><span data-reader-unique-id="939"></span><span data-reader-unique-id="940">{
</span><span data-reader-unique-id="941"></span><span data-reader-unique-id="942">// function return square power of a number</span><span data-reader-unique-id="943">
</span><span data-reader-unique-id="944"></span><span data-reader-unique-id="945">return</span><span data-reader-unique-id="946"> a * a;
</span>}

<span data-reader-unique-id="947"></span><span data-reader-unique-id="948">int</span><span data-reader-unique-id="949"></span><span data-reader-unique-id="950">cube</span><span data-reader-unique-id="951">(</span><span data-reader-unique-id="952">int</span><span data-reader-unique-id="953"> a)</span><span data-reader-unique-id="954"></span><span data-reader-unique-id="955">{
</span><span data-reader-unique-id="956"></span><span data-reader-unique-id="957">// function return cubic power of a number</span><span data-reader-unique-id="958">
</span><span data-reader-unique-id="959"></span><span data-reader-unique-id="960">return</span><span data-reader-unique-id="961"> a * a * a;
</span>}

<span data-reader-unique-id="962"></span><span data-reader-unique-id="963">int</span><span data-reader-unique-id="964"></span><span data-reader-unique-id="965">main</span><span data-reader-unique-id="966">()</span><span data-reader-unique-id="967"></span><span data-reader-unique-id="968">{
</span><span data-reader-unique-id="969"></span><span data-reader-unique-id="970">int</span><span data-reader-unique-id="971"> (*fp)(</span><span data-reader-unique-id="972">int</span><span data-reader-unique-id="973">);
</span><span data-reader-unique-id="974"></span><span data-reader-unique-id="975">// point function pointer to function square()</span><span data-reader-unique-id="976">
</span>    fp = square;
  
<span data-reader-unique-id="977"></span><span data-reader-unique-id="978">// sum = 2^2 + 3^2, as fp points to function sqaure()</span><span data-reader-unique-id="979">
</span><span data-reader-unique-id="980"></span><span data-reader-unique-id="981">int</span><span data-reader-unique-id="982"> sum = conditionalSum(</span><span data-reader-unique-id="983">2</span><span data-reader-unique-id="984">, </span><span data-reader-unique-id="985">3</span><span data-reader-unique-id="986">, fp);
</span><span data-reader-unique-id="987"></span><span data-reader-unique-id="988">printf</span><span data-reader-unique-id="989">(</span><span data-reader-unique-id="990">"Square sum = %d\n"</span><span data-reader-unique-id="991">, sum);
</span>  
<span data-reader-unique-id="992"></span><span data-reader-unique-id="993">// point function pointer to function cube()</span><span data-reader-unique-id="994">
</span>    fp = cube;
  
<span data-reader-unique-id="995"></span><span data-reader-unique-id="996">// sum = 2^3 + 3^3, as fp points to function cube()</span><span data-reader-unique-id="997">
</span><span data-reader-unique-id="998">    sum = conditionalSum(</span><span data-reader-unique-id="999">2</span><span data-reader-unique-id="1000">, </span><span data-reader-unique-id="1001">3</span><span data-reader-unique-id="1002">, fp);
</span><span data-reader-unique-id="1003"></span><span data-reader-unique-id="1004">printf</span><span data-reader-unique-id="1005">(</span><span data-reader-unique-id="1006">"Cubic sum = %d"</span><span data-reader-unique-id="1007">, sum);
</span><span data-reader-unique-id="1008"></span><span data-reader-unique-id="1009">return</span><span data-reader-unique-id="1010"></span><span data-reader-unique-id="1011">0</span><span data-reader-unique-id="1012">;
</span>}

</code></pre></div></div></pre>

**Output**

<pre data-reader-unique-id="1015"><div data-reader-unique-id="1016"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="1017"><code data-reader-unique-id="1018"><span data-reader-unique-id="1019">Square sum = </span><span data-reader-unique-id="1020">13</span><span data-reader-unique-id="1021">
</span><span data-reader-unique-id="1022">Cubic sum = </span><span data-reader-unique-id="1023">35</span><span data-reader-unique-id="1024">
</span></code></pre></div></div></pre>

Here, we have created a function** **conditionalSum** **that sums two integer numbers after modifying their value based on the callback function. When the function is called in the first case,** **fp** **was pointing to function** **square** **because of which the output of function is sum of squares of the arguments. In the second function call function pointer** **fp** **points to the function cube and the sum is returned in cubic sum of the numbers.

### Program to pass pointers with functions in c

Following is a program where we passed pointer in function argument and, changes made on it inside the function are reflected in the calling function.

<pre data-reader-unique-id="1033"><div data-reader-unique-id="1034"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="1035"><code data-reader-unique-id="1036"><span data-reader-unique-id="1037">#</span><span data-reader-unique-id="1038">include</span><span data-reader-unique-id="1039"><stdio.h></span><span data-reader-unique-id="1040">
</span>
<span data-reader-unique-id="1041"></span><span data-reader-unique-id="1042">void</span><span data-reader-unique-id="1043"></span><span data-reader-unique-id="1044">incrementSalary</span><span data-reader-unique-id="1045">(</span><span data-reader-unique-id="1046">double</span><span data-reader-unique-id="1047"> *current_salary, </span><span data-reader-unique-id="1048">double</span><span data-reader-unique-id="1049"> percentage_increment)</span><span data-reader-unique-id="1050"></span><span data-reader-unique-id="1051">{
</span><span data-reader-unique-id="1052"></span><span data-reader-unique-id="1053">double</span><span data-reader-unique-id="1054"> increment_value = (*current_salary) * (percentage_increment / </span><span data-reader-unique-id="1055">100.0</span><span data-reader-unique-id="1056">);
</span>  
<span data-reader-unique-id="1057"></span><span data-reader-unique-id="1058">// increment the salary</span><span data-reader-unique-id="1059">
</span><span data-reader-unique-id="1060"></span><span data-reader-unique-id="1061">// the changes will persist outside function scope</span><span data-reader-unique-id="1062">
</span><span data-reader-unique-id="1063"></span><span data-reader-unique-id="1064">// because the current salary reference was passed to the function</span><span data-reader-unique-id="1065">
</span>    *current_salary = *current_salary + increment_value;
}

<span data-reader-unique-id="1066"></span><span data-reader-unique-id="1067">int</span><span data-reader-unique-id="1068"></span><span data-reader-unique-id="1069">main</span><span data-reader-unique-id="1070">()</span><span data-reader-unique-id="1071"></span><span data-reader-unique-id="1072">{
</span><span data-reader-unique-id="1073"></span><span data-reader-unique-id="1074">double</span><span data-reader-unique-id="1075"> salary; 
</span><span data-reader-unique-id="1076"></span><span data-reader-unique-id="1077">double</span><span data-reader-unique-id="1078"> hike = </span><span data-reader-unique-id="1079">5.0</span><span data-reader-unique-id="1080">;
</span><span data-reader-unique-id="1081">    salary = </span><span data-reader-unique-id="1082">1000.0</span><span data-reader-unique-id="1083">;
</span>  
<span data-reader-unique-id="1084"></span><span data-reader-unique-id="1085">printf</span><span data-reader-unique-id="1086">(</span><span data-reader-unique-id="1087">"Current salary = %lf\n"</span><span data-reader-unique-id="1088">, salary);
</span>  
<span data-reader-unique-id="1089"></span><span data-reader-unique-id="1090">// passing pointer salary to the function call</span><span data-reader-unique-id="1091">
</span>    incrementSalary(&salary, hike);
  
<span data-reader-unique-id="1092"></span><span data-reader-unique-id="1093">printf</span><span data-reader-unique-id="1094">(</span><span data-reader-unique-id="1095">"Salary after %lf percent hike = %lf \n"</span><span data-reader-unique-id="1096">, hike, salary);
</span><span data-reader-unique-id="1097"></span><span data-reader-unique-id="1098">return</span><span data-reader-unique-id="1099"></span><span data-reader-unique-id="1100">0</span><span data-reader-unique-id="1101">;
</span>}



</code></pre></div></div></pre>

**Output**

<pre data-reader-unique-id="1104"><div data-reader-unique-id="1105"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="1106"><code data-reader-unique-id="1107"><span data-reader-unique-id="1108">Current salary = </span><span data-reader-unique-id="1109">1000.000000</span><span data-reader-unique-id="1110">
</span><span data-reader-unique-id="1111">Salary after </span><span data-reader-unique-id="1112">5.000000</span><span data-reader-unique-id="1113"> percent hike = </span><span data-reader-unique-id="1114">1050.000000</span><span data-reader-unique-id="1115"> 
</span></code></pre></div></div></pre>

Here, because we have passed current salary with a pointer the changes made on the address pointed by the pointer are reflected when we leave the scope of the function** **incrementSalary. This will not happen if a normal variable is passed to the function instead of a pointer variable.

We can also pass the array to functions using pointers as shown in the example

<pre data-reader-unique-id="1119"><div data-reader-unique-id="1120"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="1121"><code data-reader-unique-id="1122"><span data-reader-unique-id="1123">#</span><span data-reader-unique-id="1124">include</span><span data-reader-unique-id="1125"><stdio.h></span><span data-reader-unique-id="1126">
</span>
<span data-reader-unique-id="1127"></span><span data-reader-unique-id="1128">int</span><span data-reader-unique-id="1129"></span><span data-reader-unique-id="1130">greatest</span><span data-reader-unique-id="1131">(</span><span data-reader-unique-id="1132">int</span><span data-reader-unique-id="1133"> *, </span><span data-reader-unique-id="1134">int</span><span data-reader-unique-id="1135">)</span><span data-reader-unique-id="1136">;
</span>
<span data-reader-unique-id="1137"></span><span data-reader-unique-id="1138">int</span><span data-reader-unique-id="1139"></span><span data-reader-unique-id="1140">main</span><span data-reader-unique-id="1141">()</span><span data-reader-unique-id="1142">{
</span><span data-reader-unique-id="1143"></span><span data-reader-unique-id="1144">int</span><span data-reader-unique-id="1145"> arr[</span><span data-reader-unique-id="1146">6</span><span data-reader-unique-id="1147">] = {</span><span data-reader-unique-id="1148">4</span><span data-reader-unique-id="1149">,</span><span data-reader-unique-id="1150">5</span><span data-reader-unique-id="1151">,</span><span data-reader-unique-id="1152">22</span><span data-reader-unique-id="1153">,</span><span data-reader-unique-id="1154">77</span><span data-reader-unique-id="1155">,</span><span data-reader-unique-id="1156">23</span><span data-reader-unique-id="1157">,</span><span data-reader-unique-id="1158">1</span><span data-reader-unique-id="1159">};
</span>  
<span data-reader-unique-id="1160"></span><span data-reader-unique-id="1161">// passing base address of the array to the function</span><span data-reader-unique-id="1162">
</span><span data-reader-unique-id="1163"></span><span data-reader-unique-id="1164">int</span><span data-reader-unique-id="1165"> max_value = greatest(arr, </span><span data-reader-unique-id="1166">6</span><span data-reader-unique-id="1167">);
</span>  
<span data-reader-unique-id="1168"></span><span data-reader-unique-id="1169">printf</span><span data-reader-unique-id="1170">(</span><span data-reader-unique-id="1171">"Greatest value in array = %d"</span><span data-reader-unique-id="1172">, max_value);
</span><span data-reader-unique-id="1173"></span><span data-reader-unique-id="1174">return</span><span data-reader-unique-id="1175"></span><span data-reader-unique-id="1176">0</span><span data-reader-unique-id="1177">;
</span>}

<span data-reader-unique-id="1178"></span><span data-reader-unique-id="1179">int</span><span data-reader-unique-id="1180"></span><span data-reader-unique-id="1181">greatest</span><span data-reader-unique-id="1182">(</span><span data-reader-unique-id="1183">int</span><span data-reader-unique-id="1184"> *arr, </span><span data-reader-unique-id="1185">int</span><span data-reader-unique-id="1186"> n)</span><span data-reader-unique-id="1187"></span><span data-reader-unique-id="1188">{
</span><span data-reader-unique-id="1189"></span><span data-reader-unique-id="1190">// receiving array in an integer pointer arr</span><span data-reader-unique-id="1191">
</span><span data-reader-unique-id="1192"></span><span data-reader-unique-id="1193">// here, *arr represents the value in array at index 0 </span><span data-reader-unique-id="1194">
</span><span data-reader-unique-id="1195"></span><span data-reader-unique-id="1196">int</span><span data-reader-unique-id="1197"> max_element = arr[</span><span data-reader-unique-id="1198">0</span><span data-reader-unique-id="1199">], i;
</span><span data-reader-unique-id="1200"></span><span data-reader-unique-id="1201">for</span><span data-reader-unique-id="1202">(i = </span><span data-reader-unique-id="1203">0</span><span data-reader-unique-id="1204">; i < n; i++) {
</span><span data-reader-unique-id="1205"></span><span data-reader-unique-id="1206">if</span><span data-reader-unique-id="1207"> (max_element < arr[i]) {
</span>            max_element = arr[i];
        }
    }
<span data-reader-unique-id="1208"></span><span data-reader-unique-id="1209">return</span><span data-reader-unique-id="1210"> max_element;
</span>}

</code></pre></div></div></pre>

**Output**

<pre data-reader-unique-id="1213"><div data-reader-unique-id="1214"><div class="scrollable extendsBeyondTextColumn"><pre data-reader-unique-id="1215"><code data-reader-unique-id="1216"><span data-reader-unique-id="1217">Greatest value in </span><span data-reader-unique-id="1218">array</span><span data-reader-unique-id="1219"> = </span><span data-reader-unique-id="1220">77</span><span data-reader-unique-id="1221">
</span></code></pre></div></div></pre>

Compile these codes online with this Free** **[Online C Compiler](https://www.scaler.com/topics/c/online-c-compiler/).

### Conclusion

* Instructions inside function also live in memory and have a memory address. We can use pointers to reference functions in C. Such pointers which** ****hold a reference to a function** are called function pointers.
* Function pointers in C are required to be declared before referencing them to a function. Function pointer declaration includes function return type and data types of function arguments, which it will point to.
* Functions can both accept and return values as pointers. When pointers are passed as function argument changes made on them persist outside the function scope. This way of passing pointers to function arguments is called** ** **pass by reference** .
* When functions return a pointer, extra care should be taken not to return any address whose value might not exist outside the function scope. In such cases you such return pointer to variables that are passed to the function** ****by reference** or** ****have global scope** or are** ****created dynamically**inside the function.
* Function pointers in C can be used to create function calls to which they point. This allows programmers to pass them to functions as arguments. Such functions passed as an argument to other functions are also called** ** **callback functions** .


# Sum up

Based on the following code we can undersnatd many things:

```c
#include <stdio.h>

int main () {

   int  var = 20;   /* actual variable declaration */
   int  *ip;        /* pointer variable declaration */

   ip = &var;  /* store address of var in pointer variable*/

   printf("Address of var variable: %x\n", &var  );

   /* address stored in pointer variable */
   printf("Address stored in ip variable: %x\n", ip );

   /* access the value using the pointer */
   printf("Value of *ip variable: %d\n", *ip );

   return 0;
}
```

We can see that if we want to access the value of a pointer we need to use the asterisk *

A pointer is basicly an address. We can create variables that will accept address bu using the synatx *variable_name

We can store the address of a variable by using the syntax &variable and more specifically usually we save it onto a pointer variable.
