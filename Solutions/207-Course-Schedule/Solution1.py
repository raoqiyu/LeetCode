class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        course_indegrees = [0 for _ in range(numCourses)]
        # use dict to speed up
        course2next = {i:[] for i in range(numCourses)}
        for course,pre_course in prerequisites:
            course_indegrees[course] += 1
            course2next[pre_course].append(course)
         
        # find courses without any prerequisities
        course_can_finish_queue = []
        for i,indegrees in enumerate(course_indegrees):
            if indegrees == 0:
                course_can_finish_queue.append(i)
        num_of_course_can_finish = len(course_can_finish_queue)
        
        while course_can_finish_queue:
            # find a course without any prerequisities
            course = course_can_finish_queue.pop(0)
            # eliminate the eage begin from this course
            for pre_course in course2next[course]:
                course_indegrees[pre_course] -= 1
                # if this next course has no pre-course, this course can be finished
                if course_indegrees[pre_course] == 0:
                    course_can_finish_queue.append(pre_course)
                    num_of_course_can_finish += 1
                    
        # if the num of courses can be finished is equal to the num of total courses,
        # it is possible  to finish all courses
        return num_of_course_can_finish == numCourses
            
            
            
        
