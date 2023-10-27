import os
class Cd:
    def __init__(self, path = ""):
        if path == "":
            self.m_path = os.getcwd().replace("\\","/") + "/"
        else:
            self.m_path = path.replace("\\", "/")
    def SetPath(self, path):
        self.m_path = path
    def GetPath(self)-> str:
        return self.m_path

    def GetActualPath(self)-> str:
        return os.getcwd() + '/'
    def Ls(self) -> list:
        """ return the list of directories """
        ls = os.listdir(self.m_path)
        ls_sort = {}
        ls_sort["dir"] = []
        ls_sort["file"] = []
        for elem in ls:
            if os.path.isdir(os.path.join(self.m_path, elem)):
                ls_sort["dir"].append(elem)
        for elem in ls:
            if os.path.isfile(os.path.join(self.m_path, elem)):
                ls_sort["file"].append(elem)
        return ls_sort


    def __Split_path(self, path):
        """ Split the path """
        copy_self_path = self.m_path
        list_element_in_path = self.__Borned_by(copy_self_path, "/")
        new_path = ""
        indice_max = len(list_element_in_path)
        print(indice_max, list_element_in_path, copy_self_path)
        while path[:3] == "../":
            path = path[3:]
            indice_max -= 1
        for i in range(indice_max):
            new_path += list_element_in_path[i]
            self.m_path += list_element_in_path[i]
        new_path += path
        print(new_path, "hey", copy_self_path)
        return new_path

    def __Borned_by(self, string, separator)-> str:

        new_list = []
        string_temp = ""
        for element in string:
            if separator == str(element):
                new_list.append(string_temp)
                string_temp = ""
            else:
                string_temp += element
        return new_list

    def Exist(self, path) -> bool:
        assert isinstance(path, str), " Le chemin doit être un string "
        """ Return a bool"""
        up_list, path = self.__Split_path(path)
        return os.path.exists(up_list + path)

    def Cd(self, path) -> str :
        """ return False if  """
        assert isinstance(path, str), " Le chemin doit être un string "
        path = self.__Split_path(path)
        if not os.path.exists(path):
            return False
        print(self.m_path, path)
        return path

# test = Cd()
# print(test.Get_path())