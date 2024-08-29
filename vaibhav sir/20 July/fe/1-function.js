var name = "some name";






function foo1(param1){
    // var var1 = "var1value";
    // let let1 = "let1value";

    console.log("The value of var1 inside if block is: ", var1);
    console.log("The value of let1 inside if block is: ", let1);

    if(true){
        var var1 = "var2value";
        let let1 = "let2value";
        console.log("The value of var1 inside if block is: ", var1);
        console.log("The value of var1 inside if block is: ", var1);

    }


    console.log("Inside foo1 function with param as: ", param1);
}

var foo2 = function(param1){
    console.log("Inside foo2 function with param as: ", param1);
}

//arrow function. mujhe hamesha ek variable banana padhega isko call krne ke liye 
var foo3 = (param1) => {
    console.log("Inside foo3 function with param as: ", param1);
}

// function declaration - traditional approach. not directly calling. callback function. 
// jab mujhe iss function ko kisi aur function ke parameter mein call krna hai
(param1) => {
    console.log("Inside foo4 function with param as: ", param1);
}

// self invoking function
((param1) => {
    console.log("Inside foo4 function with param as: ", param1);
})()