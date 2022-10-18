using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace mylibcs
{
    public class MyCalculator
    {
        public bool hasPrecedence(char op1, char op2)
        {
            if (op2 == '(' || op2 == ')')
            {
                return false;
            }
            if ((op1 == '*' || op1 == '/') &&
                   (op2 == '+' || op2 == '-'))
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        /// <summary>
        /// Calculate the results for statement such as “(1+5)*(5%(10*10))
        /// </summary>
        /// <param name="expression"></param>
        /// <returns></returns>
        public int evaluateInfix(string expression)
        {
            char[] tokens = expression.ToCharArray();

            // Stack for numbers: 'values'
            Stack<int> values = new Stack<int>();

            // Stack for Operators: 'ops'
            Stack<char> ops = new Stack<char>();

            for (int i = 0; i < tokens.Length; i++)
            {
                // Current token is a whitespace, skip it
                if (tokens[i] == ' ')
                {
                    continue;
                }

                // Current token is a number,
                // push it to stack for numbers
                if (tokens[i] >= '0' && tokens[i] <= '9')
                {
                    StringBuilder sbuf = new StringBuilder();

                    // There may be more than
                    // one digits in number
                    while (i < tokens.Length &&
                            tokens[i] >= '0' &&
                                tokens[i] <= '9')
                    {
                        sbuf.Append(tokens[i++]);
                    }
                    values.Push(int.Parse(sbuf.ToString()));

                    // Right now the i points to
                    // the character next to the digit,
                    // since the for loop also increases
                    // the i, we would skip one
                    //  token position; we need to
                    // decrease the value of i by 1 to
                    // correct the offset.
                    i--;
                }

                // Current token is an opening
                // brace, push it to 'ops'
                else if (tokens[i] == '(')
                {
                    ops.Push(tokens[i]);
                }

                // Closing brace encountered,
                // solve entire brace
                else if (tokens[i] == ')')
                {
                    while (ops.Peek() != '(')
                    {
                        values.Push(applyOp(ops.Pop(),
                                         values.Pop(),
                                        values.Pop()));
                    }
                    ops.Pop();
                }

                // Current token is an operator.
                else if (tokens[i] == '+' ||
                         tokens[i] == '-' ||
                         tokens[i] == '*' ||
                         tokens[i] == '/')
                {

                    // While top of 'ops' has same
                    // or greater precedence to current
                    // token, which is an operator.
                    // Apply operator on top of 'ops'
                    // to top two elements in values stack
                    while (ops.Count > 0 &&
                             hasPrecedence(tokens[i],
                                         ops.Peek()))
                    {
                        values.Push(applyOp(ops.Pop(),
                                         values.Pop(),
                                       values.Pop()));
                    }

                    // Push current token to 'ops'.
                    ops.Push(tokens[i]);
                }
            }

            // Entire expression has been
            // parsed at this point, apply remaining
            // ops to remaining values
            while (ops.Count > 0)
            {
                values.Push(applyOp(ops.Pop(),
                                 values.Pop(),
                                values.Pop()));
            }

            // Top of 'values' contains
            // result, return it
            return values.Pop();

        }

        // A utility method to apply an
        // operator 'op' on operands 'a' 
        // and 'b'. Return the result.
        public int applyOp(char op,
                                int b, int a)
        {
            switch (op)
            {
                case '+':
                    return a + b;
                case '-':
                    return a - b;
                case '*':
                    return a * b;
                case '/':
                    if (b == 0)
                    {
                        throw new
                        System.NotSupportedException(
                               "Cannot divide by zero");
                    }
                    return a / b;
            }
            return 0;
        }

        /// <summary>
        /// This function will determine missing parenthesis in the statement (Evaluate Infix will use this function inside
        /// </summary>
        /// <param name="expression"></param>
        /// <returns></returns>
        public bool validateInfix(string expression)
        {
            int previous = 0;
            int previous1 = 0;
            string expEvaluated = string.Empty;
            int operatorOperand = 1;

            for (int i = 0; i < expression.Length; i++)
            {
                char c = expression[i];
                if (c == ')')  //if encountered ")", stop process
                {
                }
                else
                if (c == '(')  //if encountered "(", start process until ")"
                {
                    int j = expression.IndexOf(')', i);
                    if (j == -1)
                        return false;

                    string substring = expression.Substring(i + 1, j - i - 1);

                    while (getcharactercount(substring, '(') != getcharactercount(substring, ')'))
                    {
                        if (j < expression.Length - 1)
                            j = expression.IndexOf(')', j + 1);
                        else
                            break;

                        substring = expression.Substring(i + 1, j - i - 1);
                    }

                    i = j - 1; //Changing the counter i to point to the next character
                    //validating the sub expression
                    if (validateInfix(substring) == true)
                    {
                        if (previous != 0 && previous1 != 0 && previous > previous1)
                        {
                            previous1 = operatorOperand;
                            operatorOperand++;
                            previous = 0;
                        }
                        else if (previous != 0 && previous1 != 0 && previous <= previous1)
                        {
                            return false;
                        }
                        else if (previous1 != 0)
                        {
                            return false;
                        }
                        else
                        {
                            previous1 = operatorOperand;
                            operatorOperand++;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                    if (c == '+'                      // Function to perform arithmetic operations.
                   || c == '-'
                   || c == '*'
                   || c == '/')
                {
                    if (previous != 0)
                    {
                        return false;
                    }
                    previous = operatorOperand;
                    operatorOperand++;
                }
                else
                {
                    if (previous != 0 && previous1 != 0 && previous > previous1)
                    {
                        previous1 = operatorOperand;
                        operatorOperand++;
                        previous = 0;
                    }
                    else if (previous != 0 && previous1 != 0 && previous <= previous1)
                    {
                        return false;
                    }
                    else if (previous1 != 0)
                    {
                        return false;
                    }
                    else
                    {
                        previous1 = operatorOperand;
                        operatorOperand++;
                    }
                }
            }
            if (previous != 0)
                return false;
            return true;
        }

        public static int getcharactercount(string exp, char _c)  //to get the number of desired operation
        {
            int count = 0;
            foreach (char c in exp)
            {
                if (c == _c)
                    count++;
            }
            return count;
        }

        // A utility function to return
        // precedence of a given operator
        // Higher returned value means higher precedence
        public static int Prec(char ch)
        {
            switch (ch)
            {
                case '+':
                case '-':
                    return 1;

                case '*':
                case '/':
                    return 2;

                case '^':
                    return 3;
            }
            return -1;
        }

        /// <summary>
        /// This function will convert infix to postfix, and EvaluateInfix will process postfix evaluation. This function will be used in EvaluateInfix
        /// </summary>
        /// <param name="expression"></param>
        /// <returns></returns>
        public string InfixToPostfixConversion(string expression)
        {
            // initializing empty String for result
            string result = "";

            // initializing empty stack
            Stack<char> stack = new Stack<char>();

            for (int i = 0; i < expression.Length; ++i)
            {
                char c = expression[i];

                // If the scanned character is an
                // operand, add it to output.
                if (char.IsLetterOrDigit(c))
                {
                    result += c;
                }

                // If the scanned character is an '(',
                // push it to the stack.
                else if (c == '(')
                {
                    stack.Push(c);
                }

                //  If the scanned character is an ')',
                // pop and output from the stack
                // until an '(' is encountered.
                else if (c == ')')
                {
                    while (stack.Count > 0
                           && stack.Peek() != '(')
                    {
                        result += stack.Pop();
                    }

                    if (stack.Count > 0
                        && stack.Peek() != '(')
                    {
                        return "Invalid Expression"; // invalid
                                                     // expression
                    }
                    else
                    {
                        stack.Pop();
                    }
                }
                else // an operator is encountered
                {
                    while (stack.Count > 0
                           && Prec(c) <= Prec(stack.Peek()))
                    {
                        result += stack.Pop();
                    }
                    stack.Push(c);
                }
            }

            // pop all the operators from the stack
            while (stack.Count > 0)
            {
                result += stack.Pop();
            }

            return result;
        }
    }
}

