class Codec
{
public:

    // Encodes a list of strings to a single string.
    std::string encode(const std::vector<std::string>& strs)
    {
        std::string encoded;

        for (const std::string& str : strs)
        {
            unsigned char len = static_cast<unsigned char>(std::size(str));
            encoded.push_back(len);
            encoded += str;
        }

        return encoded;
    }

    // Decodes a single string to a list of strings.
    std::vector<std::string> decode(const std::string& s)
    {
        std::vector<std::string> decoded;

        for (int i = 0; i < std::size(s); )
        {
            unsigned char len = s[i++];
            decoded.push_back(s.substr(i, len));
            i += len;
        }

        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));