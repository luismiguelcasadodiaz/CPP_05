#include "Bureaucrat.hpp"




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
    } catch (std::exception& e) {
        std::cout << "✗ Caught wrong exception: " << e.what() << std::endl;
    }
}

void testConstructorGradeTooLow() {
    printTestHeader("Constructor Grade Too Low");
    
    try {
        Bureaucrat b("InvalidLow", 151);
        std::cout << "✗ Should have thrown exception but created: " << b << std::endl;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Caught wrong exception: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat b("InvalidLow2", 200);
        std::cout << "✗ Should have thrown exception" << std::endl;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Caught wrong exception: " << e.what() << std::endl;
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
    std::cout << "║       ALL TESTS COMPLETED!            ║\n";
    std::cout << "╚════════════════════════════════════════╝\n\n";
   
	try
	{
		Bureaucrat alice("Alice", 3);

		std::cout << alice << std::endl;
		alice.upGrade() ; 
		std::cout << alice << std::endl;
		alice.upGrade() ; 
		std::cout << alice << std::endl;
		alice.upGrade() ; 
		std::cout << alice << std::endl;
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "✓ Caught expected exception: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
	} 
    return 0;
}
