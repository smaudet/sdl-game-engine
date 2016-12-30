#ifndef __SGE_FONT_LOADER_HPP
#define __SGE_FONT_LOADER_HPP

#include <SDL_ttf.h>

#include <sge/assets/loader.hpp>

namespace sge
{
    class Font : public Asset<TTF_Font *>
    {
        using Asset<TTF_Font *>::Asset;
    };

    class FontDescriptor : public AssetDescriptor
    {
        using AssetDescriptor::AssetDescriptor;

        public:
            FontDescriptor(std::string const &assetname, int font_size);

            virtual size_t get_hash() const;
            virtual bool compare(AssetDescriptor const &other) const;

            int fontSize() const;

        private:
            int font_size;
    };

    class FontLoader : public AssetLoader
    {
        public:
            virtual void load(BaseAsset *asset, SDL_RWops *input);
            virtual void unload(BaseAsset *asset);
    };
}

#endif /* __SGE_FONT_LOADER_HPP */
