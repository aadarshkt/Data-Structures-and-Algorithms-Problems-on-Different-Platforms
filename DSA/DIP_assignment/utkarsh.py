import imageio as iio
import numpy as np
import matplotlib.pyplot as plt

def custom_convolution(input_img, custom_kernel):
    height, width = input_img.shape
    kernel_height, kernel_width = custom_kernel.shape
    pad_height = kernel_height // 2
    pad_width = kernel_width // 2
    padded_img = np.pad(input_img, ((pad_height, pad_height), (pad_width, pad_width)), mode='constant')
    result = np.zeros_like(input_img)
    for i in range(height):
        for j in range(width):
            region = padded_img[i:i + kernel_height, j:j + kernel_width]
            result[i, j] = np.sum(region * custom_kernel)
    return result

def custom_gaussian_filter(input_img, sigma_val, kernel_size_val):
    if kernel_size_val % 2 == 0:
        kernel_size_val += 1 
    custom_kernel = np.fromfunction(
        lambda x, y: (1/(2*np.pi*sigma_val**2)) * np.exp(-((x - (kernel_size_val-1)/2)**2 + (y - (kernel_size_val-1)/2)**2) / (2*sigma_val**2)),
        (kernel_size_val, kernel_size_val)
    )
    custom_kernel /= np.sum(custom_kernel)
    result = custom_convolution(input_img, custom_kernel)
    return result

def custom_laplacian_filter(input_img, kernel_idx, scale_val):
    laplacian_kernels = [
        np.array([[0., 1., 0.],
                  [1., -4., 1.],
                  [0., 1., 0.]]),
        np.array([[1., 1., 1.],
                  [1., -8., 1.],
                  [1., 1., 1.]]),
        np.array([[0., -1., 0.],
                  [-1., 4., -1.],
                  [0., -1., 0.]]),
        np.array([[-1., -1., -1.],
                  [-1., 8., -1.],
                  [-1., -1., -1.]])
    ]
    lap = custom_convolution(input_img.copy(), laplacian_kernels[kernel_idx])
    gradient_magnitude = 255 * (lap - np.min(lap))
    lap = (gradient_magnitude / np.max(gradient_magnitude))
    if (kernel_idx == 0 or kernel_idx == 1):
        output_img = (input_img - scale_val * lap)
    else:
        output_img = (input_img + scale_val * lap)
    output_img = np.where(output_img < 0, 255, output_img)
    return output_img

def custom_power_law_transformation(input_img, gamma_val):
    enhanced_img = np.power(input_img, gamma_val)
    return enhanced_img

def display_images(original_img, transformed_img, type_label):
    fig, ax = plt.subplots(nrows=1, ncols=2, figsize=(15, 15))
    ax[0].imshow(original_img, cmap='gray')
    ax[0].set_title('Given Image')
    ax[0].axis('off')
    ax[1].imshow(transformed_img, cmap='gray')
    ax[1].set_title(f'{type_label}')
    ax[1].axis('off')
    plt.show()

img_original = iio.imread("D:\Aadarsh\skeleton.tif")

img_filtered = custom_gaussian_filter(img_original, 3, 15)
img_laplacian = custom_laplacian_filter(img_filtered, 3, 10)
img_transformed = custom_power_law_transformation(img_laplacian, 0.6)

print("ORDER OF CUSTOM GAUSSIAN FILTER: ", 15)
print("SIGMA OF CUSTOM GAUSSIAN FILTER: ", 3)
print("CUSTOM LAPLACIAN FILTER SCALE: ", 10)
print("GAMMA VALUE: ", 0.6)

display_images(img_original, img_transformed, "Final_Image")
