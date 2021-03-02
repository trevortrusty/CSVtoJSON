class badExtension: std::exception
{
    private:
        const char* message = "CTJ: Bad file extension";

    public:
        const char* what() const noexcept override
        {
            return message;
        }
};
