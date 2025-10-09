#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"
#include <iostream>
#include <string>
#include <stdexcept>


void printTestHeader(const std::string& testName) {
    std::cout << "\n========================================\n";
    std::cout << "TEST: " << testName << "\n";
    std::cout << "========================================\n";
}

void testConstructorValid() {
    printTestHeader("Valid Constructor Tests");
    
    try {
        Bureaucrat b1("Alice", 1);
        std::cout << "✓ Created: " << b1 << std::endl;
        
        Bureaucrat b2("Bob", 75);
        std::cout << "✓ Created: " << b2 << std::endl;
        
        Bureaucrat b3("Charlie", 150);
        std::cout << "✓ Created: " << b3 << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
    }
}

void testConstructorGradeTooHigh() {
    printTestHeader("Constructor Grade Too High");
    
    try {
        Bureaucrat b("InvalidHigh", 0);
        std::cout << "✗ Should have thrown exception but created: " << b << std::endl;
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Caught wrong exception: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat b("InvalidHigh2", -5);
        std::cout << "✗ Should have thrown exception" << std::endl;
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
    }
}

void testConstructorGradeTooLow() {
    printTestHeader("Constructor Grade Too Low");
    
    try {
        Bureaucrat b("InvalidLow", 151);
        std::cout << "✗ Should have thrown exception but created: " << b << std::endl;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat b("InvalidLow2", 200);
        std::cout << "✗ Should have thrown exception" << std::endl;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
    }
}

void testGetters() {
    printTestHeader("Getter Tests");
    
    Bureaucrat b("Dave", 42);
    std::cout << "Name: " << b.getName() << " (expected: Dave)" << std::endl;
    std::cout << "Grade: " << b.getGrade() << " (expected: 42)" << std::endl;
    std::cout << (b.getName() == "Dave" && b.getGrade() == 42 ? "✓ PASS" : "✗ FAIL") << std::endl;
}

void testIncrementGrade() {
    printTestHeader("Increment Grade Tests");
    
    try {
        Bureaucrat b("Eve", 50);
        std::cout << "Initial: " << b << std::endl;
        
        b.upGrade();
        std::cout << "After increment: " << b << " (expected grade: 49)" << std::endl;
        
        b.upGrade();
        std::cout << "After 2nd increment: " << b << " (expected grade: 48)" << std::endl;
        
        std::cout << (b.getGrade() == 48 ? "✓ PASS" : "✗ FAIL") << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
    }
}

void testIncrementGradeBoundary() {
    printTestHeader("Increment Grade at Boundary");
    
    try {
        Bureaucrat b("Frank", 2);
        std::cout << "Initial: " << b << std::endl;
        
        b.upGrade();
        std::cout << "After increment: " << b << " (expected grade: 1)" << std::endl;
        
        b.upGrade();
        std::cout << "✗ Should have thrown exception after incrementing grade 1" << std::endl;
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
    }
}

void testDecrementGrade() {
    printTestHeader("Decrement Grade Tests");
    
    try {
        Bureaucrat b("Grace", 50);
        std::cout << "Initial: " << b << std::endl;
        
        b.downGrade();
        std::cout << "After decrement: " << b << " (expected grade: 51)" << std::endl;
        
        b.downGrade();
        std::cout << "After 2nd decrement: " << b << " (expected grade: 52)" << std::endl;
        
        std::cout << (b.getGrade() == 52 ? "✓ PASS" : "✗ FAIL") << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
    }
}

void testDecrementGradeBoundary() {
    printTestHeader("Decrement Grade at Boundary");
    
    try {
        Bureaucrat b("Helen", 149);
        std::cout << "Initial: " << b << std::endl;
        
        b.downGrade();
        std::cout << "After decrement: " << b << " (expected grade: 150)" << std::endl;
        
        b.downGrade();
        std::cout << "✗ Should have thrown exception after decrementing grade 150" << std::endl;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
    }
}

void testCopyConstructor() {
    printTestHeader("Copy Constructor Test");
    
    Bureaucrat b1("Ivan", 75);
    Bureaucrat b2(b1);
    
    std::cout << "Original: " << b1 << std::endl;
    std::cout << "Copy: " << b2 << std::endl;
    std::cout << "Names match: " << (b1.getName() == b2.getName() ? "✓" : "✗") << std::endl;
    std::cout << "Grades match: " << (b1.getGrade() == b2.getGrade() ? "✓" : "✗") << std::endl;
}

void testAssignmentOperator() {
    printTestHeader("Assignment Operator Test");
    
    Bureaucrat b1("Jack", 100);
    Bureaucrat b2("Jill", 50);
    
    std::cout << "Before assignment:" << std::endl;
    std::cout << "  b1: " << b1 << std::endl;
    std::cout << "  b2: " << b2 << std::endl;
    
    b2 = b1;
    
    std::cout << "After assignment (b2 = b1):" << std::endl;
    std::cout << "  b1: " << b1 << std::endl;
    std::cout << "  b2: " << b2 << std::endl;
    std::cout << "Grades match: " << (b1.getGrade() == b2.getGrade() ? "✓" : "✗") << std::endl;
}

void testOutputOperator() {
    printTestHeader("Output Operator Test");
    
    Bureaucrat b("Kate", 42);
    std::cout << "Testing operator<<: " << b << std::endl;
    std::cout << "Expected format: Kate, bureaucrat grade 42" << std::endl;
}

void testMultipleIncrements() {
    printTestHeader("Multiple Increments Test");
    
    try {
        Bureaucrat b("Larry", 10);
        std::cout << "Initial: " << b << std::endl;
        
        for (int i = 0; i < 5; i++) {
            b.upGrade();
            std::cout << "After increment " << (i + 1) << ": " << b << std::endl;
        }
        
        std::cout << (b.getGrade() == 5 ? "✓ PASS" : "✗ FAIL") << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
    }
}

void testMultipleDecrements() {
    printTestHeader("Multiple Decrements Test");
    
    try {
        Bureaucrat b("Mary", 140);
        std::cout << "Initial: " << b << std::endl;
        
        for (int i = 0; i < 5; i++) {
            b.downGrade();
            std::cout << "After decrement " << (i + 1) << ": " << b << std::endl;
        }
        
        std::cout << (b.getGrade() == 145 ? "✓ PASS" : "✗ FAIL") << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
    }
}

void testMixedOperations() {
    printTestHeader("Mixed Increment/Decrement Test");
    
    try {
        Bureaucrat b("Nancy", 75);
        std::cout << "Initial: " << b << std::endl;
        
        b.upGrade();
        std::cout << "After increment: " << b << std::endl;
        
        b.upGrade();
        std::cout << "After 2nd increment: " << b << std::endl;
        
        b.downGrade();
        std::cout << "After decrement: " << b << std::endl;
        
        std::cout << "Final grade: " << b.getGrade() << " (expected: 74)" << std::endl;
        std::cout << (b.getGrade() == 74 ? "✓ PASS" : "✗ FAIL") << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
    }
}

// ============================================================================
// FORM CLASS TESTS
// ============================================================================

void testFormConstructorValid() {
    printTestHeader("Form Valid Constructor Tests");
    
    try {
        Form f1("Tax Form", 50, 25);
        std::cout << "✓ Created form with exec=50, sign=25: " << f1 << std::endl;
        
        Form f2("Permit", 1, 1);
        std::cout << "✓ Created form with exec=1, sign=1: " << f2 << std::endl;
        
        Form f3("Registration", 150, 150);
        std::cout << "✓ Created form with exec=150, sign=150: " << f3 << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
    }
}

void testFormConstructorInvalidExecGrade() {
    printTestHeader("Form Constructor - Invalid Execute Grade");
    
    try {
        Form f("BadExec1", 0, 50);
        std::cout << "✗ Should have thrown exception for exec grade 0" << std::endl;
    } catch (Form::GradeTooHighException& e) {
        std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << "? Caught exception: " << e.what() << std::endl;
    }
    
    try {
        Form f("BadExec2", 151, 50);
        std::cout << "✗ Should have thrown exception for exec grade 151" << std::endl;
    } catch (Form::GradeTooLowException& e) {
        std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << "? Caught exception: " << e.what() << std::endl;
    }
    
    try {
        Form f("BadExec3", -10, 50);
        std::cout << "✗ Should have thrown exception for exec grade -10" << std::endl;
    } catch (Form::GradeException& e) {
        std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
    }
}

void testFormConstructorInvalidSignGrade() {
    printTestHeader("Form Constructor - Invalid Sign Grade");
    
    try {
        Form f("BadSign1", 50, 0);
        std::cout << "✗ Should have thrown exception for sign grade 0" << std::endl;
    } catch (Form::GradeTooHighException& e) {
        std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << "? Caught exception: " << e.what() << std::endl;
    }
    
    try {
        Form f("BadSign2", 50, 151);
        std::cout << "✗ Should have thrown exception for sign grade 151" << std::endl;
    } catch (Form::GradeTooLowException& e) {
        std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << "? Caught exception: " << e.what() << std::endl;
    }
    
    try {
        Form f("BadSign3", 50, 200);
        std::cout << "✗ Should have thrown exception for sign grade 200" << std::endl;
    } catch (Form::GradeTooLowException& e) {
        std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << "? Caught exception: " << e.what() << std::endl;
    }
}

void testFormGetters() {
    printTestHeader("Form Getter Tests");
    
    Form f("Application", 75, 50);
    std::cout << "Form created: " << f << std::endl;
    std::cout << "getName(): " << f.getName() << " (expected: Application)" << std::endl;
    std::cout << "getExecGrade(): " << f.getExecGrade() << " (expected: 75)" << std::endl;
    std::cout << "getSignGrade(): " << f.getSignGrade() << " (expected: 50)" << std::endl;
    std::cout << "isSigned(): " << (f.isSigned() ? "true" : "false") << " (expected: false)" << std::endl;
    
    bool pass = (f.getName() == "Application" && 
                 f.getExecGrade() == 75 && 
                 f.getSignGrade() == 50 && 
                 !f.isSigned());
    std::cout << (pass ? "✓ PASS" : "✗ FAIL") << std::endl;
}

void testFormBeSignedSuccess() {
    printTestHeader("Form beSigned - Success Cases");
    
    try {
        Bureaucrat b1("Alice", 30);
        Form f1("Document", 100, 50);
        
        std::cout << "Before signing:" << std::endl;
        std::cout << "  " << f1 << std::endl;
        std::cout << "  " << b1 << std::endl;
        std::cout << "  Form signed: " << (f1.isSigned() ? "YES" : "NO") << std::endl;
        
        f1.beSigned(b1);
        
        std::cout << "After signing:" << std::endl;
        std::cout << "  Form signed: " << (f1.isSigned() ? "YES" : "NO") << std::endl;
        std::cout << (f1.isSigned() ? "✓ PASS" : "✗ FAIL") << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Testing boundary case (exact grade) ---" << std::endl;
    try {
        Bureaucrat b2("Bob", 50);
        Form f2("License", 100, 50);
        
        std::cout << "Bureaucrat grade: " << b2.getGrade() << std::endl;
        std::cout << "Form sign grade: " << f2.getSignGrade() << std::endl;
        
        f2.beSigned(b2);
        std::cout << "Signed: " << (f2.isSigned() ? "YES ✓" : "NO ✗") << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testFormBeSignedFailure() {
    printTestHeader("Form beSigned - Failure Cases");
    
    try {
        Bureaucrat b("Charlie", 100);
        Form f("TopSecret", 150, 50);
        
        std::cout << "Attempting to sign form:" << std::endl;
        std::cout << "  Bureaucrat: " << b << std::endl;
        std::cout << "  Form: " << f << std::endl;
        std::cout << "  Bureaucrat grade: " << b.getGrade() << std::endl;
        std::cout << "  Required sign grade: " << f.getSignGrade() << std::endl;
        
        f.beSigned(b);
        
        std::cout << "✗ Should have thrown exception" << std::endl;
    } catch (Form::GradeTooLowException& e) {
        std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << "? Caught different exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Testing grade 51 trying to sign grade 50 form ---" << std::endl;
    try {
        Bureaucrat b2("Dave", 51);
        Form f2("Contract", 100, 50);
        
        std::cout << "Bureaucrat grade: " << b2.getGrade() << std::endl;
        std::cout << "Required sign grade: " << f2.getSignGrade() << std::endl;
        
        f2.beSigned(b2);
        std::cout << "✗ Should have thrown exception" << std::endl;
    } catch (Form::GradeTooLowException& e) {
        std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << "? Caught exception: " << e.what() << std::endl;
    }
}

void testFormSignMultipleTimes() {
    printTestHeader("Form Sign Multiple Times");
    
    try {
        Bureaucrat b1("Eve", 20);
        Bureaucrat b2("Frank", 30);
        Form f("Certificate", 100, 50);
        
        std::cout << "First signature attempt:" << std::endl;
        f.beSigned(b1);
        std::cout << "  Signed: " << (f.isSigned() ? "YES" : "NO") << std::endl;
        
        std::cout << "Second signature attempt (already signed):" << std::endl;
        f.beSigned(b2);
        std::cout << "  Signed: " << (f.isSigned() ? "YES" : "NO") << std::endl;
        
        std::cout << "✓ Form remains signed" << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testFormCopyConstructor() {
    printTestHeader("Form Copy Constructor Test");
    
    try {
        Form f1("Original", 75, 50);
        Bureaucrat b("Grace", 40);
        f1.beSigned(b);
        
        Form f2(f1);
        
        std::cout << "Original: " << f1 << std::endl;
        std::cout << "Copy: " << f2 << std::endl;
        std::cout << "Names match: " << (f1.getName() == f2.getName() ? "✓" : "✗") << std::endl;
        std::cout << "Exec grades match: " << (f1.getExecGrade() == f2.getExecGrade() ? "✓" : "✗") << std::endl;
        std::cout << "Sign grades match: " << (f1.getSignGrade() == f2.getSignGrade() ? "✓" : "✗") << std::endl;
        std::cout << "Signed status match: " << (f1.isSigned() == f2.isSigned() ? "✓" : "✗") << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Exception: " << e.what() << std::endl;
    }
}

void testFormAssignmentOperator() {
    printTestHeader("Form Assignment Operator Test");
    
    try {
        Form f1("FormA", 100, 75);
        Form f2("FormB", 50, 25);
        Bureaucrat b("Helen", 20);
        
        f1.beSigned(b);
        
        std::cout << "Before assignment:" << std::endl;
        std::cout << "  f1: " << f1 << std::endl;
        std::cout << "  f1 signed: " << (f1.isSigned() ? "YES" : "NO") << std::endl;
        std::cout << "  f2: " << f2 << std::endl;
        std::cout << "  f2 signed: " << (f2.isSigned() ? "YES" : "NO") << std::endl;
        
        f2 = f1;
        
        std::cout << "After assignment (f2 = f1):" << std::endl;
        std::cout << "  f1: " << f1 << std::endl;
        std::cout << "  f2: " << f2 << std::endl;
        std::cout << "  f2 signed: " << (f2.isSigned() ? "YES" : "NO") << std::endl;
        std::cout << "Signed status transferred: " << (f2.isSigned() == f1.isSigned() ? "✓" : "✗") << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Exception: " << e.what() << std::endl;
    }
}

void testFormOutputOperator() {
    printTestHeader("Form Output Operator Test");
    
    try {
        Form f1("Unsigned Form", 75, 50);
        std::cout << "Testing unsigned form output: " << f1 << std::endl;
        
        Form f2("Signed Form", 75, 50);
        Bureaucrat b("Ivan", 30);
        f2.beSigned(b);
        std::cout << "Testing signed form output: " << f2 << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Exception: " << e.what() << std::endl;
    }
}

void testFormBoundaryGrades() {
    printTestHeader("Form Boundary Grade Tests");
    
    try {
        Form f1("Highest", 1, 1);
        std::cout << "✓ Created form with grades 1,1: " << f1 << std::endl;
        
        Form f2("Lowest", 150, 150);
        std::cout << "✓ Created form with grades 150,150: " << f2 << std::endl;
        
        Form f3("Mixed1", 1, 150);
        std::cout << "✓ Created form with grades 1,150: " << f3 << std::endl;
        
        Form f4("Mixed2", 150, 1);
        std::cout << "✓ Created form with grades 150,1: " << f4 << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
    }
}

void testFormSignBoundaryBureaucrat() {
    printTestHeader("Form Sign with Boundary Bureaucrat Grades");
    
    try {
        std::cout << "Test 1: Grade 1 bureaucrat signing grade 1 form" << std::endl;
        Bureaucrat b1("TopBureaucrat", 1);
        Form f1("TopForm", 1, 1);
        f1.beSigned(b1);
        std::cout << "  Result: " << (f1.isSigned() ? "SIGNED ✓" : "NOT SIGNED ✗") << std::endl;
    } catch (std::exception& e) {
        std::cout << "  ✗ Exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nTest 2: Grade 150 bureaucrat signing grade 150 form" << std::endl;
        Bureaucrat b2("LowBureaucrat", 150);
        Form f2("LowForm", 150, 150);
        f2.beSigned(b2);
        std::cout << "  Result: " << (f2.isSigned() ? "SIGNED ✓" : "NOT SIGNED ✗") << std::endl;
    } catch (std::exception& e) {
        std::cout << "  ✗ Exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nTest 3: Grade 1 bureaucrat signing grade 150 form" << std::endl;
        Bureaucrat b3("TopBureaucrat2", 1);
        Form f3("LowForm2", 150, 150);
        f3.beSigned(b3);
        std::cout << "  Result: " << (f3.isSigned() ? "SIGNED ✓" : "NOT SIGNED ✗") << std::endl;
    } catch (std::exception& e) {
        std::cout << "  ✗ Exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\nTest 4: Grade 150 bureaucrat trying to sign grade 1 form" << std::endl;
        Bureaucrat b4("LowBureaucrat2", 150);
        Form f4("TopForm2", 1, 1);
        f4.beSigned(b4);
        std::cout << "  ✗ Should have thrown exception" << std::endl;
    } catch (Form::GradeTooLowException& e) {
        std::cout << "  ✓ Caught expected exception: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << "  ? Caught exception: " << e.what() << std::endl;
    }
}

void testFormExceptionHierarchy() {
    printTestHeader("Form Exception Hierarchy Test");
    
    try {
        Form f("Bad", 0, 50);
    } catch (Form::GradeTooHighException& e) {
        std::cout << "✓ Caught GradeTooHighException: " << e.what() << std::endl;
    } catch (Form::GradeException& e) {
        std::cout << "✓ Caught as GradeException: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << "✓ Caught as std::exception: " << e.what() << std::endl;
    }
    
    try {
        Form f("Bad", 50, 151);
    } catch (Form::GradeTooLowException& e) {
        std::cout << "✓ Caught GradeTooLowException: " << e.what() << std::endl;
    } catch (Form::GradeException& e) {
        std::cout << "✓ Caught as GradeException: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << "✓ Caught as std::exception: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║  BUREAUCRAT CLASS EXHAUSTIVE TESTING  ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    
    // Constructor tests
    testConstructorValid();
    testConstructorGradeTooHigh();
    testConstructorGradeTooLow();
    
    // Getter tests
    testGetters();
    
    // Increment tests
    testIncrementGrade();
    testIncrementGradeBoundary();
    testMultipleIncrements();
    
    // Decrement tests
    testDecrementGrade();
    testDecrementGradeBoundary();
    testMultipleDecrements();
    
    // Mixed operations
    testMixedOperations();
    
    // Copy/assignment tests
    testCopyConstructor();
    testAssignmentOperator();
    
    // Output test
    testOutputOperator();
    
    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║       BUREAUCRAT TESTS COMPLETED!      ║\n";
    std::cout << "╚════════════════════════════════════════╝\n\n";
    
    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║      FORM CLASS EXHAUSTIVE TESTING     ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    
    // Form constructor tests
    testFormConstructorValid();
    testFormConstructorInvalidExecGrade();
    testFormConstructorInvalidSignGrade();
    testFormBoundaryGrades();
    
    // Form getter tests
    testFormGetters();
    
    // Form beSigned tests
    testFormBeSignedSuccess();
    testFormBeSignedFailure();
    testFormSignMultipleTimes();
    testFormSignBoundaryBureaucrat();
    
    // Form copy/assignment tests
    testFormCopyConstructor();
    testFormAssignmentOperator();
    
    // Form output test
    testFormOutputOperator();
    
    // Form exception tests
    testFormExceptionHierarchy();
    
    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║       ALL TESTS COMPLETED!            ║\n";
    std::cout << "╚════════════════════════════════════════╝\n\n";
    
    return 0;
}
