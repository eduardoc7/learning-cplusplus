#include <string>
#include <iostream>
#include <memory>

/**
* @brief Motivation to use smart pointers is that in this case, we can use a Shared Pointer
 * to class project and share the reference with the employers.
 *
 * Study more about reference count and more tests
*/
class Project {
    std::string_view project_name;
    /** props: a list of employees that work in this project **/
public:
    void setNameProject(std::string_view name) {
        project_name = name;
    }

    void showProjectsDetails() {
        std::cout << "[Project Name] " << project_name << std::endl;
    }
};

class Employee {
    std::shared_ptr<Project> m_pProject;
public:
    /**
     * @brief shared_ptr supports copy
     * @param pointer_project pointer to the project
     */
    void setProject(const std::shared_ptr<Project> &pointer_project) {
        m_pProject = pointer_project;
    }

    const std::shared_ptr<Project> &GetProject() const {
        return m_pProject;
    }

    // test if this work using this *
    void showInfo(const std::shared_ptr<Employee> &emp) {
        std::cout << "Employee project details: ";
        emp->GetProject()->showProjectsDetails();
    }
};

static void testSharedPointers() {
    std::shared_ptr<Project> prj{new Project{}};
    prj->setNameProject("Video Decoder");

    std::shared_ptr<Employee> e1{new Employee{}};
    e1->setProject(prj);
    e1->showInfo(e1);

    std::shared_ptr<Employee> e2{new Employee{}};
    e2->setProject(prj);

    std::shared_ptr<Employee> e3{new Employee{}};
    e3->setProject(prj);

    std::cout << "Reference Count: " << prj.use_count() << std::endl;
}
