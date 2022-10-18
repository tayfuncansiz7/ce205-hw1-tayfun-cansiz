using Microsoft.VisualStudio.TestTools.UnitTesting;
using mylibcs;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mylibcs_test
{
    [TestClass]
    public class MyCalculatorTests
    {
        MyCalculator myCalculator = new MyCalculator();

        [TestMethod]
        public void TestEvaluateInfix()
        {
            string infixExpression = "4 * (2 *(1+7))/4-3";
            int result = myCalculator.evaluateInfix(infixExpression);
            int expected = 13;

            Assert.AreEqual(result, expected);
        }

        [TestMethod]
        public void TestValidateInfix()
        {
            ArrayList arr = new ArrayList();
            arr.Add("A*B(C/D)+E^F");
            foreach (string s1 in arr)
            {
                string s = s1;
                s = "(" + s + ")";
                s = s.Replace(" ", string.Empty);
                bool result = myCalculator.validateInfix(s) == true;
                bool expected = false;
                Assert.AreEqual(result, expected);
            }
        }

        [TestMethod]
        public void TestInfixToPostfixConversion()
        {
            string expression = "a+b*(c^d-e)^(f+g*h)-i";
            string result = myCalculator.InfixToPostfixConversion(expression);
            string expected = "abcd^e-fgh*+^*+i-";
            Assert.AreEqual(result, expected);
        }
    }
}
