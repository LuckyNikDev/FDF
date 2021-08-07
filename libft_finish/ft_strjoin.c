#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	size_t	result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	result = ft_strlcpy(str, s1, (ft_strlen(s1) + 1));
	result = ft_strlcpy(&str[ft_strlen(s1)], s2, (ft_strlen(s2) + 1));
	return (str);
}
