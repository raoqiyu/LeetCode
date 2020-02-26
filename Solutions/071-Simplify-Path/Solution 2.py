class Solution:
    def simplifyPath(self, path: str) -> str:
        folder_names = path.split('/')
        canonical_path = []
        for name in folder_names:
            if name == '.' or name == '':
                continue
            elif name == '..':
                if len(canonical_path) > 0:
                    canonical_path.pop()
            else:
                canonical_path.append(name)
        
        return '/' + '/'.join(canonical_path)
